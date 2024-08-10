#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mx(ll a, ll b){
    if (a>b) return a;
    return b;
}

void dfs(vector<vector<ll>>& arr, vector<bool>& vis, ll ind,vector<ll>& ch){
    vis[ind]=true;
    ll ans=0;
    for(int i=0;i<arr[ind].size();i++){
        if (!vis[arr[ind][i]]){
            dfs(arr,vis,arr[ind][i],ch);
            ans= mx(ch[arr[ind][i]],ans);
        }
        
    }
    ch[ind]=ans+1;
}

ll calche(vector<vector<ll>>& arr, vector<bool>& vis, ll ind,vector<ll>& ch){
    vis[ind]=true;
    ll ans=0;
    priority_queue<ll> cur;
    for(int i=0;i<arr[ind].size();i++){
        if (!vis[arr[ind][i]]){
            ans=mx(ans,calche(arr,vis,arr[ind][i],ch));
            cur.push(ch[arr[ind][i]]);
        }
    }
    ll cnt=0;
    ll cur2=0;
    for(int i=0;i<2;i++){
        if (!cur.empty()){
            cur2+=cur.top();
            cur.pop();
        }
    }
    //cout<<ind<<" "<<mx(ans,cur2)<<'\n';
    return mx(ans,cur2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x,a,b;
    cin>>n;
    vector<vector<ll>> arr={};
    vector<bool> vis={};
    vector<ll> ch={};
    for(int i=0;i<n;i++){
        vis.push_back(false);
        arr.push_back({});
        ch.push_back(0);
    }
    for(int i=0;i<n-1;i++){
        cin>>a; a--;
        cin>>b; b--;
        arr[a].push_back(b);
        arr[b].push_back(a);

    }
    ll ans=0;
    ll cur;
    
    ll rt;
    for(int i=0;i<n;i++){
        if (arr[i].size()==1) rt=i;
        
    }
    dfs(arr,vis,rt,ch);
    //cout<<rt<<" \n";
    for(int i=0;i<n;i++){
        //cout<<ch[i]<<" ";
        vis[i]=false;
    }
    
    cout<<calche(arr,vis,rt,ch)<<'\n';
    
    return 0;
}