#include <bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int>> &gr,int ind,int tm,vector<pair<int,int>>& times,vector<bool>&vis){
    vis[ind]=true;
    for(int i=0;i<gr[ind].size();i++){
        if (!vis[gr[ind][i]]){
            tm=dfs(gr,gr[ind][i],tm,times,vis);
        }
    }
    times[ind]={tm,ind};
    tm++;
    return tm;
}

void dfs2(vector<vector<int>> &gr,int ind,int par,vector<bool>&vis,vector<int>&scc){
    vis[ind]=true;
    scc[ind]=par;
    for(int i=0;i<gr[ind].size();i++){
        if (!vis[gr[ind][i]]){
            dfs2(gr,gr[ind][i],par,vis,scc);
        }
    }
}

vector<int> SCC(vector<vector<int>>&gr){
    int n=gr.size();
    vector<bool>vis(n,false);
    vector<pair<int,int>>times(n,{0,0});
    int tm=0;
    for(int i=0;i<n;i++){
        if (!vis[i])tm=dfs(gr,i,tm,times,vis);
    }
    
    vector<vector<int>> grt(n,vector<int>());
    for(int i=0;i<n;i++){
        for(int j=0;j<gr[i].size();j++){
            grt[gr[i][j]].push_back(i);
        }
    }
    vector<bool>vis2(n,false);
    sort(times.begin(),times.end());
    reverse(times.begin(),times.end());
    vector<int> scc(n,0);
    for(int i=0;i<n;i++){
        if (!vis2[times[i].second]){
            dfs2(grt,times[i].second,times[i].second,vis2,scc);
        }
    }
    return scc;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int n,m,a,b;
    cin>>n; cin>>m;
    vector<vector<int>> gr(n,vector<int>());
    for(int i=0;i<m;i++){
        cin>>a; cin>>b;
        gr[a-1].push_back(b-1);
    }
    vector<int> p=SCC(gr);
    int cur=1;
    map<int,int> s;
    //for(int i=0;i<n;i++) cout<<p[i]<<" ";
    //cout<<'\n';
    for(int i=0;i<n;i++){
        if (s.find(p[i])==s.end()){
            s.insert({p[i],cur});
            p[i]=cur;
            cur++;
        }
        else{
            p[i]=s[p[i]];
        }
    }
    cout<<cur-1<<'\n';
    for(int i=0;i<n;i++) cout<<p[i]<<" ";
    cout<<'\n';

}