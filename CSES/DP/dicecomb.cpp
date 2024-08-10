#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int md=pow(10,9)+7;
    ll n; 
    cin>>n;
    ll dp[n+1];
    for(int i=0;i<=n;i++) dp[i]=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if (i>=j){
                dp[i]+= dp[i-j];
                dp[i]%=md;
            }
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}