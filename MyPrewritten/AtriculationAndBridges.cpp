#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mn(ll a, ll b){
    if (a<b)return a;
    return b;
}

ll dfs(vector<vector<ll>>& gr, ll ind, vector<bool>&vis, vector<ll>& art, vector<pair<ll,ll>> & br,ll tim,vector<ll>& dt, vector<ll>& hs,ll p){
    vis[ind]=true;
    dt[ind]=tim;
    tim++;
    hs[ind]=tim-1;
    int children=0;
    bool dn=false;
    for(int i=0;i<gr[ind].size();i++){
        if (gr[ind][i]==p) continue;
        children++;
        if (!vis[gr[ind][i]]){
            tim=dfs(gr,gr[ind][i],vis,art,br,tim,dt,hs,ind);
            hs[ind]=mn(hs[ind],hs[gr[ind][i]]);
            if (hs[gr[ind][i]]>=dt[ind] && !dn && p!=-1){ // doesnt apply to root
                dn=true; // dn just to add it one time not repeatedly
                art.push_back(ind);
            }
            if (children==2 && p==-1)art.push_back(ind);

            if (hs[gr[ind][i]]>dt[ind]){
                br.push_back({ind,gr[ind][i]});
            }
        }
        hs[ind]=mn(hs[ind],dt[gr[ind][i]]);
        
        

    }
    return tim;
}

int main(){

    vector<vector<ll>> gr={{1,2,3},{0,5,2},{1,0,3,4},{0,4},{2,3},{1}};
    vector<bool> vis={false,false,false,false,false,false};
    vector<pair<ll,ll>> br={};
    vector<ll> art={},disc(6,0),highsen(6,0);

    dfs(gr,0,vis,art,br,0,disc,highsen,-1);

    for(int i=0;i<6;i++){
        cout<<disc[i]<<" "<<highsen[i]<<"\n";
    }
    cout<<'\n';
    for(int i=0;i<art.size();i++){
        cout<<art[i]<<" ";
    }
    cout<<'\n'<<'\n';
    for(int i=0;i<br.size();i++){
        cout<<br[i].first<<" "<<br[i].second<<'\n';
    }


}