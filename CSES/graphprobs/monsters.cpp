#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool bfs(vector<vector<ll>>&gr, char (*grid)[], ll (*mp)[], ll ind, ll st, vector<bool> & vis){
    vis[ind]=true;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    ll n,m,st;
    cin>>n;
    cin>>m;
    ll trav=0;
    ll par[n*m];
    char grid[n][m];
    char c;
    vector<vector<ll>> gr={};
    vector<bool> vis={};
    ll mp[n][m];
    gr.push_back({});
    vis.push_back(false);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            vis.push_back(false);
            trav++;
            if (c=='A') st=trav;
            mp[i][j]=trav;
            grid[i][j]=c;
            gr.push_back({});
            
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (grid[i][j]=='M' || grid[i][j]=='A')gr[0].push_back(mp[i][j]);
            if (grid[i][j]!='#'){
                if (i>0 && grid[i-1][j]!='#') gr[mp[i][j]].push_back(mp[i-1][j]);
                if (i<n-1 && grid[i+1][j]!='#') gr[mp[i][j]].push_back(mp[i+1][j]);
                if (j>0 && grid[i][j-1]!='#') gr[mp[i][j]].push_back(mp[i][j-1]);
                if (j<m-1 && grid[i][j+1]!='#') gr[mp[i][j]].push_back(mp[i][j+1]);
            }
            
        }
    }
    if (bfs(gr,grid,mp,0,st,vis)){
        cout<<"YES\n";
    }
    else cout<<"NO\n";



    return 0;
}