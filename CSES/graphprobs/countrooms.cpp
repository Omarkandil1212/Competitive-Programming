#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(vector<vector<ll>>& arr, ll ind ,vector<bool>& vis){
    vis[ind]=true;
    ll ans=0;
    for(int i=0;i<arr[ind].size();i++){
        if (!vis[arr[ind][i]]){
            dfs(arr,arr[ind][i],vis);
        }
        
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,m;
    cin>>n;
    cin>>m;
    ll trav=0;
    ll ans=0;
    ll arr[n][m];
    char c;
    char g[n][m];
    vector<vector<ll>> gr={};
    vector<bool> vis={};
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>c;
            g[i][j]=c;
            arr[i][j]=-1;
            if (c=='.'){
                arr[i][j]=trav;
                trav++;
                vis.push_back(false);
                gr.push_back({});
            }
        }
    }
    ll ind,ind2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (g[i][j]=='.'){
                ind=arr[i][j];
                if (i<n-1 && g[i+1][j]=='.'){
                    ind2=arr[i+1][j];
                    gr[ind].push_back(ind2);
                    gr[ind2].push_back(ind);
                }
                if (j<m-1 && g[i][j+1]=='.'){
                    ind2=arr[i][j+1];
                    gr[ind].push_back(ind2);
                    gr[ind2].push_back(ind);
                }
            }
        }
    }

    for(int i=0;i<vis.size();i++){
        if (!vis[i]){
            ans++;
            dfs(gr,i,vis);
        }

    }
    
    cout<<ans<<'\n';
   
    return 0;
}