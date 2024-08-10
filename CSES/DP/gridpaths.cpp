#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    const ll md=pow(10,9)+7;
    ll n;
    cin>>n;
    char gr[n][n];
    ll dp[n][n];
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>c;
            gr[i][j]=c;
            dp[i][j]=0;
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if (gr[i][j]=='.'){
                if (i==n-1 && j==n-1) dp[i][j]=1;
                else{
                    if (i<n-1 && gr[i+1][j]=='.') dp[i][j]+=dp[i+1][j];
                    dp[i][j]%=md;
                    if (j<n-1&& gr[i][j+1]=='.') dp[i][j]+=dp[i][j+1];
                    dp[i][j]%=md;
                }
            }
            
        }
    }
    cout<<dp[0][0]<<'\n';

}