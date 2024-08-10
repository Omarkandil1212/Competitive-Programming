#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    bitset<100001> dp;
    dp[0]=1;
    ll n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        dp=dp|(dp<<a);
    }
    ll ans=0;
    for(int i=1;i<=100001;i++){
        if (dp[i]==1) ans++;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=100001;i++){
        if (dp[i]==1) cout<<i<<" ";
    }
    cout<<'\n';

    return 0;
}