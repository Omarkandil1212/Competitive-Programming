#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&tr,int ind,vector<int>&ans){
    int cnt=0;
    for(int i=0;i<tr[ind].size();i++){
        dfs(tr,tr[ind][i],ans);
        cnt+=ans[tr[ind][i]];
    }
    cnt++;
    ans[ind]=cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    vector<vector<int>> tr(n,vector<int>());
    for(int i=0;i<n-1;i++){
        cin>>a; 
        tr[a-1].push_back(i+1);
    }
    vector<int> ans(n,0);
    dfs(tr,0,ans);
    a=0;
    for(int i=0;i<n;i++){
        cout<<ans[i]-1<<' ';
    }
    cout<<'\n';

    return 0;
}