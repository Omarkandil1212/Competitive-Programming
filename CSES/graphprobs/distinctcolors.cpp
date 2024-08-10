#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> dfs(vector<vector<int>>&tr, int ind, int p,vector<int>&ans,vector<int>&col){
    set<int> s;
    set<int> pr;
    for(int i=0;i<tr[ind].size();i++){
        if (tr[ind][i]!=p){
            pr=dfs(tr,tr[ind][i],ind,ans,col);
            if (pr.size()>s.size()) swap(pr,s);
            for(auto it=pr.begin();it!=pr.end();it++) s.insert(*it);
            
        }
    }
    s.insert(col[ind]);

    ans[ind]=s.size();
    return s;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n,a,c,b,x;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        cin>>x; arr.push_back(x);
    }
    vector<vector<int>> tr(n,vector<int>());
    for(int i=0;i<n-1;i++){
        cin>>a; cin>>b;
        a--; b--;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }
    vector<int> ans(n,0);
    dfs(tr,0,-1,ans,arr);
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    cout<<'\n';
 
    return 0;
}