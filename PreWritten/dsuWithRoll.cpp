#include <bits/stdc++.h>
using namespace std;

struct DSUwithRollBack {
	vector<int> rank, par;
    stack<pair<int,pair<int,int>>> roll;
    int comp;
	DSUwithRollBack(int n) : rank(n, 1), par(n) { iota(par.begin(), par.end(), 0); comp=n; }

	int find(int u) { 
        while(u!=par[u]) u =par[u];
        return u;
    }
	int size(int u) { return rank[find(u)]; }
    void checkpoint(){
        roll.push({-1,{-1,-1}});
    }
    void rollback(){
        pair<int,pair<int,int>> p;
        while(roll.top().first!=-1){ // assumes there is a checkpoint before
            p=roll.top();
            roll.pop();
            rank[par[p.first]]=p.second.second;
            par[p.first]=p.second.first;
            comp++;
        }
        roll.pop();
    }
	bool merge(int u, int v) {
		if((u = find(u)) == (v = find(v))) return false;
        comp--;
		if (rank[u] < rank[v]) { swap(u, v); }
        roll.push({v,{par[v],rank[u]}});
		rank[u] += rank[v];	par[v] = u;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int n,m,a,b;
    string type;
    cin>>n; cin>>m; 
    DSUwithRollBack d(n);
    for(int i=0;i<m;i++){
        cin>>type;
        if (type=="persist"){
            d.checkpoint();
        }
        else if (type=="rollback"){
            d.rollback();
            cout<<d.comp<<'\n';
        }
        else{
            cin>>a; cin>>b;
            d.merge(a-1,b-1);
            cout<<d.comp<<'\n';
        }
    }
}