#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Tree
{
    vector<vector<pair<ll,ll>>> tree;
    ll n,m,cnt;
    Tree(ll pn, ll pm): n(pn), m(pm), cnt(0) // n: num nodes; m: num edges
    {
        tree=vector<vector<pair<ll,ll>>>(n);
    }
    void addEdge(ll a, ll b)
    {
        tree[a].push_back({b,cnt});
        tree[b].push_back({a,cnt});
        cnt++;
    }

    // if only 2 nodes have odd degree, euler path exists. 
    // if all nodes have even degree, euler circuit/tour exists.
    // must also be connected. if node not connected, must have degree=0.
    vector<ll> eulerPath(ll st=-1, ll end=-1) 
    {
        vector<bool> vis(m,false);
        vector<ll> curEdge(n);
        ll cntOd=0;
        ll strt=st;
        for(int i=0;i<n;i++)
        {
            if (tree[i].size()%2)
            {
                cntOd++;
                if (strt== -1 || tree[strt].size()%2==0) strt=i;
            }
            else if (strt==-1) strt=i;
        }
        vector<ll> path;
        if (cntOd>0) return path; // >0 bcz want euler tour, if wanted path put >2
        if (st>-1 && strt!=st) return path; // no euler path starting at st; 
        // euler path must start at an odd degree node.
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
    vector<ll> eulPath = tr.eulerPath(0,0);
    if (eulPath.size())
    {
        for(auto x: eulPath) cout<<x+1<<' ';
        cout<<'\n';
    }
    else cout<<"IMPOSSIBLE\n";

    return 0;
}