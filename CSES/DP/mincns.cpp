#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,c;
    cin>>n; cin>>x;
    int dp[x+1];
    vector<int> cns;
    for(int i=0;i<n;i++){
        cin>>c; cns.push_back(c);
    }
    for(int i=0;i<=x;i++) dp[i]=-1;
    dp[0]=0;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if (cns[j]<=i){
                if (dp[i-cns[j]]==-1) continue;
                if (dp[i]==-1) dp[i]=1+dp[i-cns[j]];
                else dp[i]=min(dp[i],1+dp[i-cns[j]]);
            }
        }
    }
    cout<<dp[x]<<'\n';
    return 0;
}