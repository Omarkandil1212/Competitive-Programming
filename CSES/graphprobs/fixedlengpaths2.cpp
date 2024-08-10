#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct FT {
	int n; vector<int> vals;
	FT(int n) : n(n), vals(n + 1, 0) {}

	void update(int i, int x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	int query(int i) const { // sum from 0 ... i
		int sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	int query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<vector<int>>gr;
vector<int> sz; 
vector<bool>vis; // mark nodes already set as centroids.
FT* sg=NULL;
ll ans=0;
int k=0;
int k2=0;
int n;
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
void cntPaths(int u, int p,int dep){ // specific for this problem
    if (dep>k2) return;
    if (dep==k2){
        ans++;
        return ;
    }
    ans+= sg->query(max(0,k-dep),k2-dep);
    int v;
    for(int i=0;i<gr[u].size();i++){
        v=gr[u][i];
        if (p!=v && !vis[v]){
            cntPaths(v,u,dep+1);
        }
    }
}
void addPaths(int u, int p, int dep){ // specific for this problem
    if (dep>k2) return;
    sg->update(dep,1);
    int v;
    for(int i=0;i<gr[u].size();i++){
        v=gr[u][i];
        if (p!=v && !vis[v]){
            addPaths(v,u,dep+1);
        }
    }
}
void build(int u, int p) {
    int tot = dfs(u, p);
    int c = centroid(u, p, tot);
    //frq[0]++;
    sg->update(0,1);
    int v;
    for(int i=0;i<gr[c].size();i++){
        v=gr[c][i];
        if (!vis[v]){
            cntPaths(v,c,1);
            addPaths(v,c,1);
        }
    }

    for(int i=0;i<n;i++){
        int x = sg->query(i, i);
        if (x==0) break;
        sg->update(i,-x);
    }
    vis[c]=true;
    for(int i=0;i<gr[c].size();i++) {
        v=gr[c][i];
        if (!vis[v]) build(v,c);
    }
    //cout<<c<<" "<<p<<'\n';
}
 
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x,a,b;
    cin>>n; cin>>k; cin>>k2;
    gr=vector<vector<int>>(n,vector<int>());
    sz=vector<int>(n,0);
    vis=vector<bool>(n,false);
    sg=new FT(n);
    for(int i=0;i<n-1;i++){
        cin>>a; cin>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    ans=0;
    build(0,-1);
    cout<<ans<<'\n';
    return 0;
}