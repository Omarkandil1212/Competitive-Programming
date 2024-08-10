#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;



int main(){
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
        gr[a-1].push_back({b-1,w});
        //gr[b-1].push_back({a-1,w});
    }
    vector<ll> dist(n,LONG_LONG_MAX);
    dist[0]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,0});
    pair<ll,ll> p;
    while(!pq.empty()){
        p=pq.top();
        pq.pop();
        if (!vis[p.second]){
            vis[p.second]=true;
            for(int i=0;i<gr[p.second].size();i++){
                if (dist[p.second]+gr[p.second][i].second<dist[gr[p.second][i].first]){
                    dist[gr[p.second][i].first]=dist[p.second]+gr[p.second][i].second;
                    pq.push({dist[gr[p.second][i].first],gr[p.second][i].first});
                }
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";



    return 0;
}