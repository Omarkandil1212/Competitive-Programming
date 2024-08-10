#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mx(ll a, ll b){
    if (a>b) return a;
    return b;
}
ll maxx(ll a,ll b, ll c){
    if (a>b){
        if (c>a) return c;
        return a;
    }
    else{
        if (b>c) return b;
        return c;
    }
}

// segment tree code
struct StVal
{
    ll v,cmsm,pref,suf;
    StVal() {}
    StVal(ll _v)
    {
        v = _v;
        cmsm=_v;
        pref=_v;
        suf=_v;
    }
    
    StVal(const StVal &L, const StVal &R)
    {
        cmsm = L.cmsm+R.cmsm;
        pref=maxx(L.pref, L.cmsm + R.pref,L.pref);
        suf=maxx(R.suf, R.cmsm+ L.suf,R.suf);
        v = maxx(L.v, R.v, L.suf+R.pref);
    }
};

struct SegTree
{
    ll n;
    vector<StVal> st;
    vector<ll> leaves;
    vector<ll> v;

    SegTree(){

    }

    SegTree(ll _n, vector<ll> &_v)
    {
        n = _n;
        v = _v;
        leaves.resize(n, 0);
        init(1, 0, n - 1);
    }

    void init(ll treeIndex, ll low_range, ll high_range)
    {
        if (low_range == high_range)
        {
            // reached a leaf. Set the value of the leaf node and store the index of the leaf node in the leaves array.
            if (treeIndex >= (ll)st.size())
                st.resize(treeIndex + 1);
            st[treeIndex] = StVal(v[low_range]);
            leaves[low_range] = treeIndex; // leaves[i] = index of the leaf node containing the value v[i]
        }
        else
        {
            const ll mid = (low_range + high_range) >> 1;
            init(treeIndex << 1, low_range, mid);
            init((treeIndex << 1) + 1, mid + 1, high_range);
            // merge the values of the children nodes to get the value of the current node.
            st[treeIndex] = StVal(st[treeIndex << 1], st[(treeIndex << 1) + 1]);
        }
    }

    StVal query(ll l, ll r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(0ll); }
    StVal query(ll left_index, ll right_index, ll treeIndex, ll low_range, ll high_range)
    {
        //[left_index, right_index] is the query range
        //[low_range, high_range] is the range of the current node

        if (left_index <= low_range && high_range <= right_index)
        {
            // corresponds to base case
            //  Case when completely contained, return st[treeIndex] immediatly because full range is covered.
            return st[treeIndex];
        }

        const ll mid = (low_range + high_range) >> 1;
        if (right_index <= mid)
        {
            
            return query(left_index, right_index, (treeIndex << 1), low_range, mid);
        }
        if (mid < left_index)
        {
            
            return query(left_index, right_index, (treeIndex << 1) + 1, mid + 1, high_range);
        }
        
        return StVal(query(left_index, right_index, (treeIndex << 1), low_range, mid),
                     query(left_index, right_index, (treeIndex << 1) + 1, mid + 1, high_range));
    }

    
    void update(ll i, ll x)
    {
        
        ll treeIndex = leaves[i];
       
        st[treeIndex] = StVal(x);
        
        treeIndex = treeIndex >> 1;
        
        for (; treeIndex; treeIndex = (treeIndex >> 1))
        {
            st[treeIndex] = StVal(st[treeIndex << 1], st[(treeIndex << 1) + 1]);
        }
    }
};

struct HeavyLightdecomp{ // head contains which path they belong to represented by a leader node
    ll n;                // heavy of node is the child with largest subtree. -1 for leaf
    vector<int> parent, depth, heavy, head, pos;
    map<pair<ll,ll>,ll> vals;
    vector<bool> vis;
    int cur_pos;
    SegTree sg;
    int dfs(int v, vector<vector<int>> const& adj) {
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v]) {
            if (c != parent[v]) {
                parent[c] = v, depth[c] = depth[v] + 1;
                int c_size = dfs(c, adj);
                size += c_size;
                if (c_size > max_c_size)
                    max_c_size = c_size, heavy[v] = c;
            }
        }
        return size;
    }
    void updateval(int v, ll s){
        sg.update(pos[v],s);
    }
    void decompose(int v, int h, vector<vector<int>> const& adj, int p) { // assumes 0 is root
        
        if (p!=-1) sg.update(cur_pos,vals[{p,v}]);
        else sg.update(cur_pos,LONG_MIN);
        vis[v]=true;
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h, adj,v);
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c, adj,v);
        }
    }
    HeavyLightdecomp(vector<vector<int>> const& adj, map<pair<ll,ll>,ll>& values) { // adjacency list of tree
        n = adj.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        vals=map<pair<ll,ll>,ll>();
        cur_pos = 0;
        for(auto it=values.begin();it!=values.end();it++) vals.insert(*it);
        vector<ll> arr(n,0);
        vis=vector<bool>(n,false);
        sg= SegTree(n,arr);
        
        for(int i=0;i<n;i++){
            if (vis[i])continue;
            
            dfs(i, adj);
            decompose(i, i, adj,-1);
        }
        
    }

    ll query(int a, int b) {
        ll v1 = LONG_MIN; ll suf1=LONG_MIN; ll pref1=LONG_MIN;
        ll cmsm1=0;
        ll v2 = LONG_MIN; ll suf2=LONG_MIN; ll pref2=LONG_MIN;
        ll cmsm2=0;
        bool on=true;
        int a1=a,b1=b;
        while (head[a] != head[b]) { // logn. while they are not on same path
            b1=b;
            if (depth[head[a]] > depth[head[b]]){
                b1=a;
                on=true;
            }
            else on=false;   
            StVal s1 = sg.query(pos[head[b1]], pos[b1]); // logn
            if (on){
                v1=maxx(v1,s1.v,pref1+s1.suf);
                suf1=mx(suf1, cmsm1+s1.suf);
                pref1=mx(pref1+s1.cmsm,s1.pref);
                cmsm1+= s1.cmsm;
                
            }
            else{
                v2=maxx(v2,s1.v,pref2+s1.suf);
                suf2=mx(suf2, cmsm2+s1.suf);
                pref2=mx(pref2+s1.cmsm,s1.pref);
                cmsm2+= s1.cmsm;
            }
            if (on) a=parent[head[b1]];
            else b=parent[head[b1]];
        }
        if (depth[a] > depth[b]) {
            swap(a, b);
            on=true;
        }
        else on=false;
        
        if (a!=b){
            StVal s1= sg.query(pos[a]+1, pos[b]);
            if (on){
                v1=maxx(v1,s1.v,pref1+s1.suf);
                suf1=mx(suf1, cmsm1+s1.suf);
                pref1=mx(pref1+s1.cmsm,s1.pref);
                cmsm1+= s1.cmsm;
                
            }
            else{
                v2=maxx(v2,s1.v,pref2+s1.suf);
                suf2=mx(suf2, cmsm2+s1.suf);
                pref2=mx(pref2+s1.cmsm,s1.pref);
                cmsm2+= s1.cmsm;
            }
        }
        v1=maxx(v1,v2,pref1+pref2);
        return v1;
    }
};

struct DSU {
	vector<ll> rank, par;

	DSU(ll n) : rank(n, 1), par(n) { iota(par.begin(), par.end(), 0); }

	ll find(const ll &u) { return par[u] == u ? u : (par[u] = find(par[u])); }
	ll size(ll u) { return rank[find(u)]; }

	bool merge(ll u, ll v) {
		if((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	par[v] = u;
		return true;
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t,n,q,u,v,type;
    ll x;
    cin>>t;
    while(t--){
        cin>>n; cin>>q;
        DSU d(n);
        vector<vector<int>> queries={};
        vector<vector<int>> gr(n,vector<int>());
        set<int> seen;
        vector<ll> vals(n,0);
        map<pair<ll,ll>,ll> mpval;
        for(int i=0;i<q;i++){
            cin>>type;
            if (type==1){
                cin>>u; cin>>v; cin>>x;
                if (d.find(u-1)!=d.find(v-1)){
                    gr[u-1].push_back(v-1);
                    gr[v-1].push_back(u-1);
                    mpval.insert({{u-1,v-1},x});
                    mpval.insert({{v-1,u-1},x});
                    //vals[v-1]=x;
                    d.merge(u-1,v-1);
                }
                
            }
            else {
                cin>>u; cin>>v;
            }
            vector<int> v1={type,u-1,v-1};
            queries.push_back(v1);
        }


        
        HeavyLightdecomp hld(gr,mpval);
        DSU dd(n);
        int vert1,vert2;
        for(int i=0;i<q;i++){
            vert1=queries[i][1];
            vert2=queries[i][2];
            if (queries[i][0]==1){
                dd.merge(vert1,vert2);
            }
            else{
                if (dd.find(vert1)!=dd.find(vert2)) cout<<"Nope\n";
                else{
                    cout<<hld.query(vert1,vert2)<<'\n';
                }
            }
        }
    }


    return 0;
}