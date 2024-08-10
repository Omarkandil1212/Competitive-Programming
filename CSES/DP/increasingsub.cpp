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
    ll x,n,v,ind;
    cin>>n;
    vector<ll> orig={};
    map<ll,ll> mxind;
    map<ll,ll> allind;
    vector<ll> seg(n,-1);
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>x;
        orig.push_back(x);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if (mxind.find(arr[i])==mxind.end()) mxind.insert({arr[i],i});
        else mxind[arr[i]]=i;
        if (allind.find(arr[i])==allind.end()) allind.insert({arr[i],i});
    }
    SegTree sg(n,seg);
    for(int i=n-1;i>=0;i--){
        ind=mxind[orig[i]]+1;
        v=1;
        if (ind<n){
            v=mx(v,sg.query(ind,n-1).v +1);
        }
        //cout<<orig[i]<<" "<<v<<"\n";
        sg.update(allind[orig[i]],v);
        allind[orig[i]]++;
    }
    cout<<sg.query(0,n-1).v<<'\n';
    
   

    return 0;
}