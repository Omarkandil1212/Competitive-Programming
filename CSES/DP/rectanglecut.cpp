#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll mn(ll a, ll b){
    if (a<b) return a;
    return b;
} 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a,b;
    cin>>a; cin>>b;
    ll dp[a+1][b+1];
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if (i==j) dp[i][j]=0;
            else{
                dp[i][j]=LONG_LONG_MAX;
                for(int k=1;k<i;k++){
                    dp[i][j]=mn(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                }
                for(int k=1;k<j;k++){
                    dp[i][j]=mn(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }
    /*for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    cout<<dp[a][b]<<'\n';


    return 0;
}