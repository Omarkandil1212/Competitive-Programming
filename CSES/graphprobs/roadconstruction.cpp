#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> rank, par,size;

	DSU(int n) : rank(n, 1), par(n),size(n,1) { iota(par.begin(), par.end(), 0); }

	int find(const int &u) { return par[u] == u ? u : (par[u] = find(par[u])); }
	bool merge(int u, int v) {
		if((u = find(u)) == (v = find(v))) return false;
		if (size[u] < size[v]) { swap(u, v); }
		size[u] += size[v];	par[v] = u;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int n,m,a,b;
    cin>>n; cin>>m;
    DSU d(n);
    int comp=n;
    int mx=1;
    for(int i=0;i<m;i++){
        cin>>a; cin>>b;
        if (d.merge(a-1,b-1)){
            comp--;
            d.find(a-1);
            if (d.size[d.par[a-1]]>mx)mx=d.size[d.par[a-1]];
        }
        cout<<comp<<" "<<mx<<'\n';
    }

}