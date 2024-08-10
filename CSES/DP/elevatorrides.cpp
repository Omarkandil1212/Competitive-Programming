#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,w;
    cin>>n; cin>>x;
    vector<int> ppl;
    for(int i=0;i<n;i++){
        cin>>w;
        ppl.push_back(w);
    }
    vector<bool> vis(n,false);

    vector<pair<int,int>> dp(pow(2,n),{n,x+1});
    dp[0].first=1;
    dp[0].second=0;
    int cur,jmp,cnt;
    pair<int,int> p;
    for(int i=1;i<dp.size();i++){
        cur=i;
        jmp=1;
        cnt=0;
        while(cur>0){
            if (cur%2==1){
                p=dp[i-jmp];
                if (p.second+ppl[cnt]>x){
                    p.first=p.first+1;
                    p.second=ppl[cnt];
                }
                else{
                    p.second+=ppl[cnt];
                }
                if (p.first<dp[i].first){
                    dp[i].first=p.first;
                    dp[i].second=p.second;
                }
                else if (p.first==dp[i].first){
                    dp[i].second=min(dp[i].second,p.second);
                }
            }
            cnt++;
            jmp=2*jmp;
            cur=cur/2;
        }
    }
    //for(int i=0;i<dp.size();i++){
    //    cout<<dp[i].first<<" "<<dp[i].second<<"\n";
    //}
    cout<<dp[dp.size()-1].first<<'\n';
    return 0;
}