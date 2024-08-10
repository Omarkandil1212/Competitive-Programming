#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,k,a,b;
    cin>>n;
    cin>>m;
    cin>>k;
    vector<ll> as = vector<ll>();
    vector<ll> bs = vector<ll>();
    for(int i=0;i<n;i++){
        cin>>a;
        as.push_back(a);
    }
    for(int i=0;i<m;i++){
        cin>>b;
        bs.push_back(b);
    }
    ll ans=0;
    sort(as.begin(),as.end());
    sort(bs.begin(),bs.end());
    ll i,j,dif;
    i=0;j=0;
    while(i<n && j<m){
        dif = as[i]-bs[j];
        if (dif<0) dif=-dif;
        if (dif<=k){
            ans++;
            i++;
            j++;
        }
        else{
            if (as[i]>bs[j]) j++;
            else i++;
        }
    }
    cout<<ans<<'\n';
    return 0;
}