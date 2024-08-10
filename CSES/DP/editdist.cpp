#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mn(ll a, ll b, ll c){
    //cout<<a<<" "<<b<<" "<<c<<'\n';
    if (a<=b && a<=c) return a;
    if (b<=c && b<=a) return b;
    return c;
}

int main(){
    ll n,m;
    string s1,s2;
    cin>>s1; cin>>s2;
    n=s1.size(); m =s2.size();
    ll dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        dp[i][m]=n-i;
    }
    for(int i=0;i<=m;i++){
        dp[n][i]=m-i;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            
            if(s1[i]==s2[j]){ 
                //cout<<i<<" "<<j<<" "<<dp[i+1][j+1]<<" "<<1+dp[i+1][j]<<'\n';
                dp[i][j]=dp[i+1][j+1];
            }
            if (s1[i]!=s2[j]){
                dp[i][j]=1+ mn(dp[i+1][j+1],dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    /*
    cout<<'\n';
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    */
    cout<<dp[0][0]<<'\n';


    return 0;
}