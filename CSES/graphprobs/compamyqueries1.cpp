#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class TreeAncestor {
public:
    int sz;
    int lg;
    vector<int> prnt;
    vector<vector<ll>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        //cout<<"here \n";
        sz=n;
        //prnt=parent;
        lg=floor(log2(n))+1;
        //int dp[lg][n];
        for(int i=0;i<lg;i++){
            dp.push_back({});
        }
        for(int i=0;i<n;i++){
            
            dp[0].push_back(parent[i]);
        }
        //cout<<"here2\n";
        for(int i=1;i<lg;i++){
            for(int j=0;j<n;j++){
                //cout<<i<<" "<<j<<'\n';
                if (dp[i-1][j]==-1) dp[i].push_back(-1);
                else dp[i].push_back(dp[i-1][dp[i-1][j]]);
                
            }
        }
        
        
        
    }
    
    int getKthAncestor(int node, int k) {
        int jmp;
        while(k>0){
            jmp=floor(log2(k));
            k-=pow(2,jmp);
            node=dp[jmp][node];
            if (node==-1) break;
        }
        if (node!=-1) node++;
        return node;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q,p,x,k;
    cin>>n; cin>>q;
    vector<int> par(n,-1);
    for (int i=1;i<n;i++){
        cin>>p; p--;
        par[i]=p;
    }
    TreeAncestor t(n,par);
    for(int i=0;i<q;i++){
        cin>>x; cin>>k; x--;
        cout<<t.getKthAncestor(x,k)<<'\n';
    }
    return 0;
}