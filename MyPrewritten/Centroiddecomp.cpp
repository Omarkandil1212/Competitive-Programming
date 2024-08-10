#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>>gr;
vector<int> sz; 
vector<bool>vis; // mark nodes already set as centroids.
vector<int> frq;
vector<int> par;
int dfs(int u, int p) {
    sz[u] = 1;
    int v;
    for(int i=0;i<gr[u].size();i++){
        v=gr[u][i];
        if (v!=p && !vis[v])sz[u] += dfs(v, u);
    }
    return sz[u];
}
int centroid(int u, int p, int totSize) {
    int v;
    for(int i=0;i<gr[u].size();i++){
        v=gr[u][i];
        if (v!=p && !vis[v]){
            if(sz[v] > totSize / 2) return centroid(v, u, totSize);
        }
        
    }
    return u;
}
void cntPaths(int u, int p,int& k, int dep,ll& ans){ // specific for the problem
    if (dep>k) return;
    ans+= frq[k-dep];
    int v;
    for(int i=0;i<gr[u].size();i++){
        v=gr[u][i];
        if (p!=v && !vis[v]){
            cntPaths(v,u,k,dep+1,ans);
        }
    }
}
void addPaths(int u, int p,int& k, int dep){ // specific for the problem
    if (dep>k) return;
    frq[dep]++;
    int v;
    for(int i=0;i<gr[u].size();i++){
        v=gr[u][i];
        if (p!=v && !vis[v]){
            addPaths(v,u,k,dep+1);
        }
    }
}
void build(int u, int p,int& k,ll&ans) {
    int tot = dfs(u, p);
    int c = centroid(u, p, tot);
    
    frq[0]++;
    int v;
    for(int i=0;i<gr[c].size();i++){
        v=gr[c][i];
        if (!vis[v]){
            cntPaths(v,c,k,1,ans);
            addPaths(v,c,k,1);
        }
    }
    int n=frq.size();
    for(int i=0;i<n;i++){
        if (frq[i]==0) break;
        frq[i]=0;
    }
    par[c] = p;
    vis[c]=true;
    for(int i=0;i<gr[c].size();i++) {
        v=gr[c][i];
        if (!vis[v]) build(v,c,k,ans);
    }
}
 
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,a,b;
    int k;
    cin>>n; cin>>k;
    gr=vector<vector<int>>(n,vector<int>());
    sz=vector<int>(n,0);
    par=vector<int>(n,-1);
    vis=vector<bool>(n,false);
    frq=vector<int>(n,0);
    for(int i=0;i<n-1;i++){
        cin>>a; cin>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    ll ans=0;
    build(0,-1,k,ans);
    cout<<ans<<'\n';
    return 0;
}