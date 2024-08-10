#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void bfs(vector<string>& gr, ll i1,ll j1 ,vector<vector<bool>>& vis,vector<vector<char>>& par, ll n, ll m){
    vis[i1][j1]=true;
    
    queue<pair<ll,ll>> q;
    q.push({i1,j1});
    pair<ll,ll> p;
    while(!q.empty()){
        p=q.front();
        q.pop();
        i1=p.first;
        j1=p.second;
        //cout<<i1<<" "<<j1<<'\n';
        if (i1>0 && !vis[i1-1][j1] && gr[i1-1][j1]!='#'){
            vis[i1-1][j1]=true;
            par[i1-1][j1]='U';
            q.push({i1-1,j1});
        }
        if (i1<n-1 && !vis[i1+1][j1] && gr[i1+1][j1]!='#'){
            vis[i1+1][j1]=true;
            par[i1+1][j1]='D';
            q.push({i1+1,j1});
        }
        if (j1>0 && !vis[i1][j1-1] && gr[i1][j1-1]!='#'){
            vis[i1][j1-1]=true;
            par[i1][j1-1]='L';
            q.push({i1,j1-1});
        }
        if (j1<m-1 && !vis[i1][j1+1] && gr[i1][j1+1]!='#'){
            par[i1][j1+1]='R';
            vis[i1][j1+1]=true;
            q.push({i1,j1+1});
            //cout<<"YES\n";
        }
    }


    
    
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll i2,j2;
    ll n,m;
    cin>>n;
    cin>>m;
    ll i1,j1;
    vector<string> grid={};
    vector<vector<bool>> vis={};
    vector<vector<char>> par={};
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        grid.push_back(s);
        vis.push_back({});
        par.push_back({});
        for(int j=0;j<m;j++){
            if (s[j]=='A'){
                i1=i;
                j1=j;
            }
            if (s[j]=='B'){
                i2=i;
                j2=j;
            }
            //cout<<i<<" ";
            vis[i].push_back(false);
            par[i].push_back('0');
        }
    }
    //for(int i=0;i<n;i++){
        //for(int j=0;j<m;j++) cout<<par[i][j]<<" "<<vis[i][j]<<" ";
        //cout<<'\n';
    
    bfs(grid,i1,j1,vis,par,n,m);
    
    vector<char> ans={};
    if (par[i2][j2]=='0') cout<<"NO\n";
    else{
        while(grid[i2][j2]!='A'){
            ans.push_back(par[i2][j2]);
            if (par[i2][j2]=='U') i2++;
            else if (par[i2][j2]=='D') i2--;
            else if (par[i2][j2]=='R') j2--;
            else j2++;
        }
        cout<<"YES\n";
        cout<<ans.size()<<'\n';
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i];
        cout<<"\n";
    }


    return 0;
}
