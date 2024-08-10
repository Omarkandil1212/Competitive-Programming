#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll md=pow(10,9)+7;
int main(){
    ll n,t;
    cin>>n;
    t=(n*(n+1))/4;
    ll dp[t+1][n+1];
    for(int i=0;i<n;i++) dp[0][i]=1;
    vector<ll> arr={};
    for(int i=1;i<=n;i++) arr.push_back(i);
    for(int i=1;i<=t;i++) dp[i][0]=0;
    for(int i=1;i<=t;i++){
        for(int j=0;j<=n;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]+=dp[i][j-1];
            if (dp[i][j] >= 2*md) dp[i][j]%=md;
            if (i-arr[j-1]>=0) dp[i][j]+=dp[i-arr[j-1]][j-1];
            if (dp[i][j] >= 2*md) dp[i][j]%=md;
        }
    }
    /*
    for(int i=1;i<=t;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    */
    if ((n*(n+1)/2) %2 ==1) cout<<0<<'\n';
    else cout<<dp[t][n]/2<<'\n';
    
    
    return 0;
}