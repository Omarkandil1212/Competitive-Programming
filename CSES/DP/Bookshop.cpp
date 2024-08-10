#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int maxx(int a, int b){
    if (a>b) return a;
    return b;
}  

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x,n,h,s;
    cin>>n; cin>>x;
    vector<int> pag = vector<int>();
    vector<int> pr = vector<int>();
    for (int i=0;i<n;i++){
        cin>>h;
        pr.push_back(h);
    }
    for (int i=0;i<n;i++){
        cin>>s;
        pag.push_back(s);
    }
    int dp[1001][n+1];
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=1000;i++){
        dp[i][0]=0;
    }
    int ind=1;
    int gob;
    //cout<<"here"<<'\n';
    for(int i=1;i<=x;i++){
        for (int j=1;j<=n;j++){
            if (i-pr[j-1]>=0){
                gob = ind-pr[j-1];
                if (gob<0) gob = 1001+ gob;
                dp[ind][j]= maxx(dp[ind][j-1], dp[gob][j-1] + pag[j-1]);
            }
            else {
                dp[ind][j]=dp[ind][j-1];
            }
        }
        ind++;
        if (ind ==1001) ind=0;
    }
    //cout<<"here2\n";
    /*for(int i=0;i<=x;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }
    */
    if (ind==0) ind=1000;
    else ind--;
    cout<<dp[ind][n]<<'\n';
    return 0;
}