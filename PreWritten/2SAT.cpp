#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct twosat{
	int n; // this is double the number of terms.
	vector<vector<int>> adj, adj_t;
	vector<bool> used;
	vector<int> order, comp;
	vector<bool> assignment;
	twosat(int n){
		this->n=n;
        adj=vector<vector<int>>(n,vector<int>());
        adj_t=vector<vector<int>>(n,vector<int>());
	}

	void dfs1(int v) {
		used[v] = true;
		for (int u : adj[v]) {
			if (!used[u])
				dfs1(u);
		}
		order.push_back(v);
	}

	void dfs2(int v, int cl) {
		comp[v] = cl;
		for (int u : adj_t[v]) {
			if (comp[u] == -1)
				dfs2(u, cl);
		}
	}

	bool solve_2SAT() {
		order.clear();
		used.assign(n, false);
		for (int i = 0; i < n; ++i) {
			if (!used[i])
				dfs1(i);
		}

		comp.assign(n, -1);
		for (int i = 0, j = 0; i < n; ++i) {
			int v = order[n - i - 1];
			if (comp[v] == -1)
				dfs2(v, j++);
		}

		assignment.assign(n / 2, false);
		for (int i = 0; i < n; i += 2) {
			if (comp[i] == comp[i + 1])
				return false;
			assignment[i / 2] = comp[i] > comp[i + 1];
		}
		return true;
	}

	void add_disjunction(int a, bool na, int b, bool nb) {
		// na and nb signify whether a and b are to be negated 
		a = 2*a ^ na;
		b = 2*b ^ nb;
		int neg_a = a ^ 1;
		int neg_b = b ^ 1;
		adj[neg_a].push_back(b);
		adj[neg_b].push_back(a);
		adj_t[b].push_back(neg_a);
		adj_t[a].push_back(neg_b);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
    int n,m,x,r;
    cin>>n>>m;
    vector<int> op;
    for(int i=0;i<n;i++){
        cin>>x; op.push_back(x);
    }
    vector<vector<int>> cntr(n,vector<int>());
    for(int i=0;i<m;i++){
        cin>>r;
        for(int j=0;j<r;j++){
            cin>>x;
            cntr[x-1].push_back(i);
        }
    }
    twosat ts(2*m);
    for(int i=0;i<n;i++){
        if (op[i]==1){
            ts.add_disjunction(cntr[i][0],false,cntr[i][1],true);
            ts.add_disjunction(cntr[i][0],true,cntr[i][1],false);
        }
        else{
            ts.add_disjunction(cntr[i][0],true,cntr[i][1],true);
            ts.add_disjunction(cntr[i][0],false,cntr[i][1],false);
        }
    }
    if (ts.solve_2SAT()) cout<<"YES\n";
    else cout<<"NO\n";

	return 0;
}