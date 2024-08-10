#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&tr,int ind,int p,vector<bool>&ans){
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]!=p){
            dfs(tr,tr[ind][i],ind,ans);
            if (ans[ind]) continue;
            if (!ans[tr[ind][i]]){
                ans[tr[ind][i]]=true;
                ans[ind]=true;
            }
        }
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
    vector<bool> ans(n,false);
    dfs(tr,0,-1,ans);
    a=0;
    for(int i=0;i<n;i++){
        if (ans[i]) a++;
    }
    cout<<a/2<<'\n';
    return 0;
}