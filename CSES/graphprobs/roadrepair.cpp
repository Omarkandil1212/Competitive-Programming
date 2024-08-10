#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct DSU {
	vector<int> rank, par;

	DSU(int n) : rank(n, 1), par(n) { iota(par.begin(), par.end(), 0); }

	int find(const int &u) { return par[u] == u ? u : (par[u] = find(par[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		if((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	par[v] = u;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    ll n,m,a,b,w;
    cin>>n; cin>>m;
    DSU d(n);
    multimap<ll,pair<ll,ll>> pq;
    for(int i=0;i<m;i++){
        cin>>a; cin>>b; cin>>w;
        pq.insert({w,{a-1,b-1}});
    }
    ll ans=0;
    for(auto it=pq.begin();it!=pq.end();it++){
        //cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<'\n';
        if (d.find(it->second.first)!=d.find(it->second.second)){
            d.merge(it->second.first,it->second.second);
            ans+=it->first;
        }
    }
    int par = d.find(0);
    bool cn=true;
    for(int i=0;i<n;i++){
        if (d.find(i)!=par) cn=false;
    }
    if (cn)cout<<ans<<'\n';
    else cout<<"IMPOSSIBLE\n";

}