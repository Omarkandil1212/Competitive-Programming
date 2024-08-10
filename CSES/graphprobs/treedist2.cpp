#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll calcsum(vector<vector<ll>>&tr,ll ind,ll p,vector<ll>&sm,vector<ll>&sz){
    ll cnt=0;
    ll num=0;
    ll prev;
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]!=p){
            prev=calcsum(tr,tr[ind][i],ind,sm,sz);
            cnt+=sm[tr[ind][i]];
            num+=prev;
        }
    }
    cnt+=num;
    num++;
    sz[ind]=num;
    sm[ind]=cnt;
    return num;
}

void dfs(vector<vector<ll>>&tr,ll ind,ll p,vector<ll>&sm,vector<ll>&ans,vector<ll>&sz,ll n){
    if (p==-1) ans[ind]=sm[ind];
    else{
        ans[ind]=ans[p]+n- 2*sz[ind];
    }
    //cout<<ind<<" "<<cntup<<' '<<nodesup<<' '<<sm[ind]<<'\n';
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]!=p){
            dfs(tr,tr[ind][i],ind,sm,ans,sz,n);
           
        }
    }

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,a,b;
    cin>>n;
    vector<vector<ll>> tr(n,vector<ll>());
    for(int i=0;i<n-1;i++){
        cin>>a; cin>>b;
        a--; b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }   
    vector<ll> sm(n,0);
    vector<ll> sz(n,0);
    vector<ll> ans(n,0);
    calcsum(tr,0,-1,sm,sz);
    //for(int i=0;i<n;i++) cout<<sm[i]<<' ';
    dfs(tr,0,-1,sm,ans,sz,n);

    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    cout<<'\n';

    return 0;
}