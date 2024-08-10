#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

//#define int long long

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
    // use this if you want to combine two nodes
    StVal(const StVal &L, const StVal &R)
    {
        cmsm = L.cmsm+R.cmsm;
        pref=maxx(L.pref, L.cmsm + R.pref,0);
        suf=maxx(R.suf, R.cmsm+ L.suf,0);
        v = maxx(L.v, R.v, L.suf+R.pref);
    }
};

struct SegTree
{
    ll n;
    vector<StVal> st;
    vector<ll> leaves;
    vector<ll> v;

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

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<ll> arr=vector<ll>();
    ll n,q,q1,q2,x,mx,cur,l,r;
    cin>>n;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    SegTree sg(n,arr);


    for(int i=0;i<q;i++){
        cin>>q1;
        cin>>q2;
        sg.update(q1-1,q2);
        cout<<maxx(sg.query(0,n-1).v,0,0)<<'\n';
    }

    return 0;
}