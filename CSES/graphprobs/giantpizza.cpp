#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes[2]; int n;
	Graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void addEdge(int u, int v, bool posU, bool posV) {
		int pu = u << 1 | !posU, pv = v << 1 | !posV;
		int nu = u << 1 | posU, nv = v << 1 | posV;
		addEdge(nu, pv); addEdge(nv, pu);
	}
	void addEdge(int u, int v) {
		nodes[0][u].emplace_back(v);
		nodes[1][v].emplace_back(u);
	}

	void sccDFS(int cur, vector<bool>& vis, vector<int>& comp, bool rev) {
		vis[cur] = true;
		for (auto& e : nodes[rev][cur])
			if (!vis[e]) sccDFS(e, vis, comp, rev);
		comp.push_back(cur);
	}

	vector<int> SCC(int& t) {
		vector<bool> vis(n, false);
		vector<int> order={}, component={};
		vector<int> scc(n,0);

		for (int i = 0; i < n; i++)
			if (!vis[i]) { sccDFS(i, vis, order, false); }
        //cout<<"here\n";
		vis.assign(n, false);
		for (int i = 0; i < n; i++) {
            //cout<<i<<" ";
			int v = order[n - 1 - i];
            //cout<<i<<'\n';
			if (!vis[v]) {
				sccDFS(v, vis, component, true);
				for (auto& x : component) { scc[x] = t; }
				component.clear(); t++;
			}
		}
		return scc;
	}

	vector<int> twoSAT() {
		int t = 0; vector<int> scc = SCC(t);
		vector<int> res(n >> 1);
		for (int i = 0; i < n; i += 2) {
			if (scc[i] == scc[i + 1]) { return vector<int>(); }
			res[i >> 1] = scc[i] > scc[i + 1];
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int n,m,a,b;
    char c1,c2;
    cin>>n; cin>>m;
    Graph g(2*m);
    for(int i=0;i<n;i++){
        cin>>c1; cin>>a;
        cin>>c2; cin>>b;
        //cout<<c1<<"  "<<c2<<"  "<<a<<"  "<<b<<'\n';
        g.addEdge(a-1,b-1,c1=='+',c2=='+');
    }
    int t=0;
    //g.SCC(t);
    vector<int> res=g.twoSAT();
    if (res.size()==0) cout<<"IMPOSSIBLE";
    else{
        for(int i=0;i<res.size();i++){
            if (res[i]==1) cout<<'+'<<" ";
            else cout <<'-'<<" ";
        }
    }
    
    cout<<'\n';
}