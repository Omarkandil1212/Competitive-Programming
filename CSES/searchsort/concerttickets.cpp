#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t,n,m,a;
    map<ll,ll> freq=map<ll,ll>();
    cin>>n; cin>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        a=-a;
        if (freq.find(a)==freq.end())freq.insert({a,1});
        else freq[a]++;
    }
    vector<ll> res={};
    for(int i=0;i<m;i++){
        cin>>t; t=-t;
        auto it = freq.lower_bound(t);
        if (it->first==freq.size()) res.push_back(-1);
        else{
            res.push_back(-it->first);
            freq[it->first]--;
            if (freq[it->first]==0) freq.erase(it->first);
        }

    }
    for(int i=0;i<m;i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';

    return 0;
}