#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mx(ll a, ll b){
    if (a>b) return a;
    return b;
}

struct StVal
{
    ll v;
    StVal() {}
    StVal(ll _v)
    {
        v = _v;
    }
    // use this if you want to combine two nodes
    StVal(const StVal &L, const StVal &R)
    {
        v = mx(L.v,R.v);
    }
};

struct SegTree
{
    int n;
    vector<StVal> st;
    vector<ll> leaves;
    vector<ll> v;

    SegTree(){

    }

    SegTree(int _n, vector<ll> &_v)
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
        // divide range into 2 parts,
        // [low_range, mid] (range covered by left children)
        // [mid+1, high_range] (range covered by right children)
        // for each of the 2 children check which part it covers.
        if (right_index <= mid)
        {
            // go to left children exclusively
            return query(left_index, right_index, (treeIndex << 1), low_range, mid);
        }
        if (mid < left_index)
        {
            // go to right children exclusively
            return query(left_index, right_index, (treeIndex << 1) + 1, mid + 1, high_range);
        }
        // go to both children.
        return StVal(query(left_index, right_index, (treeIndex << 1), low_range, mid),
                     query(left_index, right_index, (treeIndex << 1) + 1, mid + 1, high_range));
    }

    // Currently Incremental Point Updates
    void update(ll i, ll x)
    {
        // get the treeIndex corresponding to the index we want to update.
        ll treeIndex = leaves[i];
        // update this value
        st[treeIndex] = StVal(x);
        // update all the parents of this node.
        treeIndex = treeIndex >> 1;
        // as long as treeIndex is not 0, keep updating the parents.
        for (; treeIndex; treeIndex = (treeIndex >> 1))
        {
            // merge the values of the children nodes to get the value of the current node.
            st[treeIndex] = StVal(st[treeIndex << 1], st[(treeIndex << 1) + 1]);
        }
    }
};

struct HeavyLightdecomp{ // head contains which path they belong to represented by a leader node
    ll n;                // heavy of node is the child with largest subtree. -1 for leaf
    vector<int> parent, depth, heavy, head, pos;
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

    void decompose(int v, int h, vector<vector<int>> const& adj) { // assumes 0 is root
        sg.update(cur_pos,v); // value of node is its index
        head[v] = h, pos[v] = cur_pos++;
        if (heavy[v] != -1)
            decompose(heavy[v], h, adj);
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v])
                decompose(c, c, adj);
        }
    }

    HeavyLightdecomp(vector<vector<int>> const& adj) { // adjacency list of tree
        n = adj.size();
        parent = vector<int>(n);
        depth = vector<int>(n);
        heavy = vector<int>(n, -1);
        head = vector<int>(n);
        pos = vector<int>(n);
        cur_pos = 0;
        
        vector<ll> arr(n,0);
        sg= SegTree(n,arr);
        dfs(0, adj);
        decompose(0, 0, adj);
    }

    int query(int a, int b) {
        int res = 0;
        for (; head[a] != head[b]; b = parent[head[b]]) { // logn
            if (depth[head[a]] > depth[head[b]])
                swap(a, b);
            int cur_heavy_path_max = sg.query(pos[head[b]], pos[b]).v; // logn
            res = max(res,cur_heavy_path_max);
        }
        if (depth[a] > depth[b]) swap(a, b);
        int last_heavy_path_max = sg.query(pos[a], pos[b]).v;
        res = mx(res,last_heavy_path_max);
        return res;
    }
};
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<vector<int>> gr={{3,5},{3},{3},{1,2,0},{5},{0,4}};
    HeavyLightdecomp hld(gr);
    cout<<hld.query(1,0)<<'\n';
    return 0;
}