#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll md=pow(10,9)+7;
int main(){
    ll n,m,a;
    cin>>n; cin>>m;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    ll dp[m+1][n];
    for(int i=0;i<=m;i++){
        for(int j=0;j<n;j++) {
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<n-1;i++){
        if (arr[i]>0){
            if (arr[i]<m){ 
                dp[arr[i]+1][i+1] += dp[arr[i]][i];
                dp[arr[i]+1][i+1]%=md;
            }
            if (arr[i]>1){
                dp[arr[i]-1][i+1] += dp[arr[i]][i];
                dp[arr[i]-1][i+1]%=md;
            }
            dp[arr[i]][i+1] += dp[arr[i]][i];
            dp[arr[i]][i+1]%=md; 
        }
        else{
            for (int j=1;j<=m;j++){
                if (dp[j][i]>0){
                    if (j<m){ 
                        dp[j+1][i+1] += dp[j][i];
                        dp[j+1][i+1]%=md;
                    }
                    if (j>1){
                        dp[j-1][i+1] += dp[j][i];
                        dp[j-1][i+1]%=md;
                    }
                    dp[j][i+1] += dp[j][i];
                    dp[j][i+1]%=md; 
                }
            }
        }
        
    }
    ll ans=0;
    if (arr[n-1]==0){
        for(int i=1;i<=m;i++){
            ans+= dp[i][n-1];
            ans%=md;
        }
    }
    else ans+= dp[arr[n-1]][n-1];
    cout<<ans<<'\n';
    return 0;
}