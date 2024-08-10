#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfstop(vector<vector<ll>>& gr,vector<ll>& res,vector<bool>& vis ,ll ind){
    vis[ind]=true;
    for(int i=0;i<gr[ind].size();i++){
        if (!vis[gr[ind][i]]){
            dfstop(gr,res,vis,gr[ind][i]);
        }
    }
    res.push_back(ind);
}

vector<ll> topsort(vector<vector<ll>>& gr, ll n){
    vector<ll> res={};
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if (!vis[i]) dfstop(gr,res,vis,i);
    }
    reverse(res.begin(),res.end());
    return res;
}
const ll md=pow(10,9)+7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n,m,st,a,b;
    bool rch=false;
    ll w;
    cin>>n; cin>>m;
    vector<vector<ll>> gr(n,vector<ll>());
    vector<ll> dp(n,0);
    for(int i=0;i<m;i++){
        cin>>a; cin>>b;
        gr[a-1].push_back(b-1);
    }
    vector<ll> tp=topsort(gr,n);
    dp[n-1]=1;
    for(int i=n-2;i>=0;i--){
        a=tp[i]; if (a==n-1) continue;
        for(int j=0;j<gr[a].size();j++){
            dp[a]+= dp[gr[a][j]];
            dp[a]%=md;
        }
    }
    cout<<dp[0]<<'\n';

    return 0;
}