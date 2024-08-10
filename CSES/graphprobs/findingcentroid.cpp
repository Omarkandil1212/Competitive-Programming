#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int fh(vector<vector<int>>&tr,int ind,vector<int>&h,int p){
    int ans=0;
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]!=p)ans+=fh(tr,tr[ind][i],h,ind);
    }
    return h[ind]=ans+1;
}

void dfs(vector<vector<int>>&tr,int ind,vector<int>&h,int up,vector<int>&ans,int p,int n){
    int m1=0; 
    bool isv=true;
    if (up>n/2) isv=false;
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]==p) continue;
        m1+= h[tr[ind][i]];
        if (h[tr[ind][i]] > n/2) isv=false;
    }
    if (isv){
        ans.push_back(ind);
        return;
    }
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]==p) continue;
        dfs(tr,tr[ind][i],h,up+m1+1-h[tr[ind][i]],ans,ind,n);
    }
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    vector<vector<int>> tr(n,vector<int>());
    for(int i=0;i<n-1;i++){
        cin>>a; cin>>b;
        a--; b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    vector<int> hts(n,0);
    vector<int> ans;
    fh(tr,0,hts,-1);
    dfs(tr,0,hts,0,ans,-1,n);
    cout<<ans[0]+1<<'\n';

    return 0;
}