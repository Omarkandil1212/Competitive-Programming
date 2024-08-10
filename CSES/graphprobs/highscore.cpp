#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    ll n,m,st,a,b,w;
    cin>>n; cin>>m;
    vector<vector<pair<ll,ll>>> gr={};
    vector<bool> vis={};
    for(int i=0;i<n;i++){
        gr.push_back({});
        vis.push_back(false);
    }
    for(int i=0;i<m;i++){
        cin>>a; cin>>b; cin>>w;
        gr[a-1].push_back({b-1,-w});
        //gr[b-1].push_back({a-1,w});
    }
    vector<ll> dist(n,LONG_LONG_MAX);
    dist[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (dist[j]==LONG_LONG_MAX) continue;
            for (int k=0;k<gr[j].size();k++){
                if (dist[j]+gr[j][k].second<dist[gr[j][k].first]){
                    dist[gr[j][k].first]=dist[j]+gr[j][k].second;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (dist[j]==LONG_LONG_MAX) continue;
            for (int k=0;k<gr[j].size();k++){
                if (vis[j]) vis[gr[j][k].first]=true;
                if (dist[j]+gr[j][k].second<dist[gr[j][k].first]){
                    dist[gr[j][k].first]=dist[j]+gr[j][k].second;
                    vis[gr[j][k].first]=true;
                    vis[j]=true;
                }
            }
        }
    }
    if (vis[n-1]) cout<<-1<<'\n';
    else cout<<-dist[n-1]<<'\n';
}