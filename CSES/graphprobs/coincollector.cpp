#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dfs(vector<vector<int>> &gr,int ind,int tm,vector<pair<int,int>>& times,vector<bool>&vis){
    vis[ind]=true;
    for(int i=0;i<gr[ind].size();i++){
        if (!vis[gr[ind][i]]){
            tm=dfs(gr,gr[ind][i],tm,times,vis);
        }
    }
    times[ind]={tm,ind};
    tm++;
    return tm;
}

void dfs2(vector<vector<int>> &gr,int ind,int par,vector<bool>&vis,vector<int>&scc){
    vis[ind]=true;
    scc[ind]=par;
    for(int i=0;i<gr[ind].size();i++){
        if (!vis[gr[ind][i]]){
            dfs2(gr,gr[ind][i],par,vis,scc);
        }
    }
}

vector<int> SCC(vector<vector<int>>&gr){// the return is specific to the problem
    int n=gr.size();
    vector<bool>vis(n,false);
    vector<pair<int,int>>times(n,{0,0});
    int tim=0;
    for(int i=0;i<n;i++)
    {
        if (vis[i]) continue;
        tim=dfs(gr,i,tim,times,vis);
    }
    vector<vector<int>> grt(n,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<gr[i].size();j++){
            grt[gr[i][j]].push_back(i);
        }
    }
    vector<bool>vis2(n,false);
    sort(times.begin(),times.end());
    reverse(times.begin(),times.end());
    vector<int> scc(n,0);
    for(int i=0;i<n;i++){
        if (!vis2[times[i].second]){
            dfs2(grt,times[i].second,times[i].second,vis2,scc);
        }
    }
    return scc;
}

ll calc(vector<vector<int>>&gr, int ind, vector<bool>&vis, vector<ll>&dp,vector<ll>&tot)
{
    vis[ind]=true;
    ll ans=tot[ind];
    ll mx=0;
    for(int i=0;i<gr[ind].size();i++)
    {
        if (!vis[gr[ind][i]])
        {
            mx=max(mx,calc(gr,gr[ind][i],vis,dp,tot));
        }
        else mx=max(mx,dp[gr[ind][i]]);
    }
    return dp[ind]=mx+ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n,m,a,b;
    cin>>n>>m;
    vector<ll> cns(n);
    vector<vector<int>> gr(n);
    for(auto&x:cns) cin>>x;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        a--; b--;
        gr[a].push_back(b);
    }
    vector<int> scc=SCC(gr);
    //for(auto x:scc) cout<<x<<' ';
    //cout<<'\n';
    
    vector<bool> vis(n,false);
    vector<ll> dp(n),tot(n);
    vector<vector<int>> gr2(n);
    for(int i=0;i<n;i++)
    {
        tot[scc[i]]= tot[scc[i]] + cns[i];
        for(int j=0;j<gr[i].size();j++)
        {
            gr2[scc[i]].push_back(scc[gr[i][j]]);
        }
    }
    int v;
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        v=scc[i];
        if (!vis[v])
        {
            ans=max(ans,calc(gr2,v,vis,dp,tot));
        }
    }
    cout<<ans<<'\n';
    

    return 0;
}