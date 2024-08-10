#include <bits/stdc++.h>
using namespace std;
typedef long int ll;


ll mn(ll a, ll b){
    if (a<b) return a;
    return b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q,m,a,b;
    ll w;
    cin>>n; cin>>m; cin>>q;
    vector<vector<ll>> gr={};
    vector<vector<ll>> dist={};
    for(int i=0;i<n;i++){
        vector<ll> mp(n,LONG_MAX);
        gr.push_back(mp);
        dist.push_back(mp);
    }
    for(int i=0;i<m;i++){
        cin>>a; cin>>b; cin>>w;
        gr[a-1][b-1]=mn(gr[a-1][b-1],w);
        gr[b-1][a-1]=mn(gr[b-1][a-1],w);
    }
    for(int i=0;i<n;i++){
        vector<bool> vis(n,false);
        dist[i][i]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0,i});
        pair<ll,int> p;
        while(!pq.empty()){
            p=pq.top();
            pq.pop();
            if (!vis[p.second]){
                vis[p.second]=true;
                for(int j=0;j<n;j++){
                    if (gr[p.second][j]==LONG_MAX) continue;
                    if (dist[i][p.second]+gr[p.second][j]<dist[i][j]){
                        dist[i][j]=dist[i][p.second]+gr[p.second][j];
                        pq.push({dist[i][j],j});
                    }
                }
            }
        }
    }
    for(int i=0;i<q;i++){
        cin>>a; cin>>b; a--; b--;
        if (dist[a][b]==LONG_MAX)cout<<-1<<'\n';
        else cout<<dist[a][b]<<'\n';
    }
    
    



    return 0;
}