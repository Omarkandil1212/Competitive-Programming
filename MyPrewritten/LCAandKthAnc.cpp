#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class TreeAncestor {
public:
    int sz;
    int lg;
    vector<int> prnt;
    vector<vector<int>> dp;
    vector<int> depth;
    TreeAncestor(int n, vector<int>& parent) {
        sz=n;
        lg=floor(log2(n))+1;
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
    }
    
    int getKthAncestor(int node, int k) {
        int jmp=pow(2,lg-1);// might need to make ll if size large
        for(int i=lg-1;i>=0;i--){
            if (jmp<=k){
                node=dp[i][node];
                k-=jmp;
            }
            jmp/=2;
        }
        return node;
    }
    int getdepth(int u){
        int ans=0;
        int jmp=pow(2,lg-1);
        for(int i=lg-1;i>=0;i--){
            if (dp[i][u]>-1){
                ans+=jmp;
                u=dp[i][u];
            }
            jmp/=2;
        }
        return ans;
    }
    int lca(int u, int v){
        int d1,d2;
        if (depth[u]==-1) depth[u]=getdepth(u);
        if (depth[v]==-1) depth[v]=getdepth(v);
        d1=depth[u];
        d2=depth[v];
        if (d1>d2){
            u=getKthAncestor(u,d1-d2);
        }
        else if (d1<d2){
            v=getKthAncestor(v,d2-d1);
        }
        if (u==v) return u;
        for(int i=lg-1;i>=0;i--){
            if (dp[i][u]!=dp[i][v]){
                u=dp[i][u];
                v=dp[i][v];
            }
        }
        return dp[0][u];
    }
};

int main(){
    int n,x;
    cin>>n;
    vector<int> arr={};
    arr.push_back(-1);
    for(int i=0;i<n-1;i++){
        cin>>x;
        arr.push_back(x-1);
    }
    int ans=0;
    int t;
    TreeAncestor ta(n,arr);
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            if (i!=j){
                t=ta.lca(i,j);
                cout<<i<<" "<<j<<' '<<t<<"\n";
                if (t != i && t!=j) ans++;
            }
        }
    }
    cout<<ans<<'\n';
    
    return 0;
}