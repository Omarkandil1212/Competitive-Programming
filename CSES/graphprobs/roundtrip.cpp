#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dfs(vector<vector<ll>>& arr, ll ind ,vector<int>& vis,vector<ll>& par){
    vis[ind]=1;
    ll ans=0;
    for(int i=0;i<arr[ind].size();i++){
        if (vis[arr[ind][i]]==1){
            if (par[ind]!=arr[ind][i]){ 
                par[arr[ind][i]]=ind;
                return arr[ind][i];
            }
        }

        if (vis[arr[ind][i]]==0){
            par[arr[ind][i]]=ind;
            ans=dfs(arr,arr[ind][i],vis,par);
            if (ans>-1) return ans;
        }
        
    }
    vis[ind]=2;
    return -1;
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,a,b;
    cin>>n;
    cin>>m;
    vector<vector<ll>> gr={};
    vector<ll> par={};
    vector<int> vis={};
    for(int i=0;i<n;i++){
        gr.push_back({});
        vis.push_back(0);
        par.push_back(-1);
    }

    for(int i=0;i<m;i++){
        cin>>a; cin>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);

    }
    ll ind,ans;
    ans=-1;
    for(int i=0;i<n;i++){
        if (vis[i]>0)continue;
        ind=dfs(gr,i,vis,par);
        if (ind>-1) {
            ans=ind;
            break;
        }
    }
    if (ans==-1) cout<<"IMPOSSIBLE\n";

    else{
        vector<ll> pth={};
        pth.push_back(ans);
        ind=par[ans];
        while(ind!=ans){
            pth.push_back(ind);
            ind=par[ind];
        }
        pth.push_back(ans);
        cout<<pth.size()<<'\n';
        for(int i=0;i<pth.size();i++)cout<<pth[i]+1<<" ";
        cout<<'\n';
    }

    return 0;
}