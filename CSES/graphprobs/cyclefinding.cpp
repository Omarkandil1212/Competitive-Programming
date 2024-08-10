#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<vector<pair<ll,ll>>>& gr,int ind, vector<bool>&vis){
    vis[ind]=true;
    for(int i=0;i<gr[ind].size();i++){
        if (!vis[gr[ind][i].first])dfs(gr,gr[ind][i].first,vis);  
    }
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n,m,st,a,b;
    ll w;
    cin>>n; cin>>m;
    vector<vector<pair<ll,ll>>> gr={};
    vector<ll> leng(n,-1),par(n,-1);
    vector<bool> vis={};
    for(int i=0;i<n;i++){
        gr.push_back({});
        vis.push_back(false);
    }
    for(int i=0;i<m;i++){
        cin>>a; cin>>b; cin>>w;
        gr[a-1].push_back({b-1,w});
    }
    vector<ll> dist(n,LONG_LONG_MAX);
    for(int i=0;i<n;i++){
        if (!vis[i]){
            dfs(gr,i,vis);
            dist[i]=0;
        }
    }
    int v1=-1,v2=-1,v3;
    for(int i=0;i<n;i++){
        v1=-1;
        for(int j=0;j<n;j++){
            if (dist[j]==LONG_LONG_MAX) continue;
            for (int k=0;k<gr[j].size();k++){
                //cout<<j<<" "<<dist[j]<<" "<<gr[j][k].first<<'\n';
                if (dist[j]+gr[j][k].second<dist[gr[j][k].first]){
                    dist[gr[j][k].first]=dist[j]+gr[j][k].second;
                    par[gr[j][k].first]=j;
                    v1=gr[j][k].first;
                }
            }
        }
    }
    if (v1==-1) cout<<"NO\n";
    else{
        for(int i=0;i<n;i++) v1=par[v1];
        v2=v1;
        //cout<<v1<<'\n';
        vector<int> ans;
        while(par[v1]!=v2){
            ans.push_back(v1);
            v1=par[v1];
        }
        ans.push_back(v1);
        ans.push_back(v2);
        cout<<"YES\n";
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]+1<<' ';
    }



}