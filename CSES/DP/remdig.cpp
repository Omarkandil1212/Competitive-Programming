#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll minn(ll a, ll b){
    if (a<b) return a;
    return b;
} 
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    cin>>n;
    ll dp[n+1];
    dp[0]=0;
    ll nm;
    int j;
    for(int i=1;i<n;i++){
        dp[i] = LONG_LONG_MAX;
    }
    for (int i=1;i<=n;i++){
        if (i<10) dp[i]=1;
        else{
            nm =i;
            while(nm>0){
                j = nm%10;
                if (j>0){
                    dp[i] = minn(dp[i],dp[i-j]+1);
                }
                nm/=10;
                
            }
        }
    }
    cout<<dp[n]<<'\n';



    return 0;
}