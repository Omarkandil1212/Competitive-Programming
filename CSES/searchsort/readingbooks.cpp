#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x,ans,fr,sm;
    cin>>n;
    sm=0;
    vector<ll> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    fr=v[0];
    ans=fr;
    for(int i=1;i<n;i++){
        sm+=v[i];
        ans+=v[i];
    }
    if (fr>sm) ans+= fr-sm;

    cout<<ans<<'\n';

    return 0;
}