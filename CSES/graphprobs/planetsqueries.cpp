#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class TreeAncestor {
public:
    int sz;
    ll lg;
    vector<int> prnt;
    vector<vector<int>> dp;
    vector<int> depth;
    TreeAncestor(int n, vector<int>& parent) {
        sz=n;
        lg=floor(log2(1e9+1))+1;
        for(int i=0;i<lg;i++){
            dp.push_back({});
        }
        for(int i=0;i<n;i++){
            depth.push_back(-1);
            dp[0].push_back(parent[i]);
        }
        for(int i=1;i<lg;i++){
            for(int j=0;j<n;j++){
                if (dp[i-1][j]==-1) dp[i].push_back(-1);
                else dp[i].push_back(dp[i-1][dp[i-1][j]]);
                
            }
        }
        //for(int i=0;i<5;i++){
        //    for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";
        //    cout<<'\n';
        //}

    }
    int getKthAncestor(int node, ll k) {
        ll jmp=pow(2,lg-1);
        for(int i=lg-1;i>=0;i--){
            if (jmp<=k){
                node=dp[i][node];
                k-=jmp;
            }
            jmp/=2;
        }
        return node;
    }
    
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,q;
    ll k;
    cin>>n; cin>>q;
    vector<int> children={};
    for(int i=0;i<n;i++){
        cin>>x; children.push_back(x-1);
    }
    TreeAncestor ta(n,children);
    for(int i=0;i<q;i++){
        cin>>x; cin>>k;
        if (k==0) cout<<x<<'\n';
        else cout<<ta.getKthAncestor(x-1,k)+1<<'\n';
    }


    return 0;
}