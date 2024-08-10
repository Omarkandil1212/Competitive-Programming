#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,a,b;
    cin>>n;
    vector<pair<ll,pair<ll,ll>>> ppl={};
    for(int i=0;i<n;i++){
        cin>>a; cin>>b;
        ppl.push_back({a,{b,i}});
    }
    sort(ppl.begin(),ppl.end());
    multimap<ll,pair<ll,ll>> cur;
    vector<ll> res(n,0);
    ll ans=1,x1,y1,i1;
    for(int i=0;i<n;i++){
        x1=ppl[i].first; y1=ppl[i].second.first; i1 = ppl[i].second.second;
        if (cur.upper_bound(-x1)==cur.end()){
            res[i1]=ans;
            ans++;
            cur.insert({-y1,{ans-1,i1}});
        }
        else{
            auto it = cur.upper_bound(-x1);
            res[i1]=(it->second.first);
            cur.erase(cur.upper_bound(-x1));
            cur.insert({-y1,{it->second.first,i1}});
        }
    }
    cout<<ans-1<<"\n";
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<'\n';

    return 0;
}