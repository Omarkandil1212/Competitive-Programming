#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Tree
{
    vector<vector<pair<ll,ll>>> tree;
    vector<ll> inD,outD;
    ll n,m,cnt;
    Tree(ll pn, ll pm): n(pn), m(pm), cnt(0) // n: num nodes; m: num edges
    {
        tree=vector<vector<pair<ll,ll>>>(n);
        inD= vector<ll>(n);
        outD = vector<ll>(n);
    }
    void addEdge(ll a, ll b)
    {
        tree[a].push_back({b,cnt});
        cnt++;
        inD[b]++;
        outD[a]++;
    }

    // directed graph case:
    // if only 2 nodes have odd degree, euler path exists. one has in-out=1, other one has out-in=1,
    // rest have equal in,out 
    // if all nodes have equal in,out degrees that are even, euler circuit/tour exists.
    // must also be a connected graph. if node not connected, its degree must be =0.
    vector<ll> eulerPath(ll st=-1, ll end=-1) 
    {
        vector<bool> vis(m,false);
        vector<ll> curEdge(n);
        ll cntOdin=0, cntOdout=0;
        ll strt=st;
        for(int i=0;i<n;i++)
        {
            if (abs(inD[i]-outD[i])>1) return {};
            if (outD[i]-inD[i]==1)
            {
                cntOdout++;
                strt=i;
            }
            if (inD[i]-outD[i]==1) cntOdin++;
            if (strt==-1) strt=i;
        }
        vector<ll> path;
        if (cntOdin>1 || cntOdout>1) return path;
        if (st>-1 && strt!=st) return path; // no euler path starting at st; 
        // euler path must start at an odd outDegree node.
        stack<ll> stck;
        stck.push(strt);
        ll v;
        pair<ll,ll> pr;
        while(!stck.empty())
        {
            v=stck.top(); 
            while(curEdge[v]<tree[v].size() && vis[tree[v][curEdge[v]].second]) curEdge[v]++;
            if (curEdge[v]==tree[v].size())
            {
                stck.pop();
                path.push_back(v);
            }
            else{
                vis[tree[v][curEdge[v]].second]=true;
                stck.push(tree[v][curEdge[v]].first);
            }
        }
        if (count(vis.begin(), vis.end(), false)) return {};
        reverse(path.begin(),path.end());
        if (end>-1 && path[path.size()-1]!=end) return {};// path doesnt end at end
        return path;
    }

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,a,b;
    cin>>n>>m;
    Tree tr(n,m);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--; b--;
        tr.addEdge(a,b);
    }
    vector<ll> eulPath = tr.eulerPath(0,n-1);
    if (eulPath.size())
    {
        for(auto x: eulPath) cout<<x+1<<' ';
        cout<<'\n';
    }
    else cout<<"IMPOSSIBLE\n";

    return 0;
}