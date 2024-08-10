#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int fh(vector<vector<int>>&tr,int ind,vector<int>&h,int p){
    int ans=0;
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]!=p)ans=max(ans,fh(tr,tr[ind][i],h,ind));
    }
    return h[ind]=ans+1;
}

void dfs(vector<vector<int>>&tr,int ind,vector<int>&h,int up,vector<int>&ans,int p){
    int m1=0; int m2=0; int ind1=-1; int ind2=-1;
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]==p) continue;
        if (h[tr[ind][i]]>m1){
            m2=m1;
            ind2=ind1;
            m1=h[tr[ind][i]];
            ind1=tr[ind][i];
        }
        else if (h[tr[ind][i]]>m2){
            m2=h[tr[ind][i]];
            ind2=tr[ind][i];
        }
    }
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]==p) continue;
        if (ind1==tr[ind][i]) dfs(tr,tr[ind][i],h,max(up,m2)+1,ans,ind);
        else dfs(tr,tr[ind][i],h,max(up,m1)+1,ans,ind);
    }
    ans[ind]=max(h[ind]-1,up);
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
    vector<int> ans(n,0);
    fh(tr,0,hts,-1);
    dfs(tr,0,hts,0,ans,-1);
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    cout<<'\n';

    return 0;
}