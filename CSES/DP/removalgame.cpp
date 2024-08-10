#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll mx(ll a,ll b){
    if (a>b) return a;
    return b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll x,n,v1,v2;
    cin>>n;
    ll cmsm=0;
    vector<ll> cm={};
    vector<ll> dp1={};
    vector<ll> dp2;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>x;
        cmsm+=x;
        arr.push_back(x);
        cm.push_back(cmsm);
        dp1.push_back(x);
    }
    for(int i=1;i<n;i++){
        dp2={};
        for(int j=0;j<n-i;j++){
            v1=arr[j] -dp1[j+1]+cm[i+j]-cm[j];
            v2=arr[j+i]- dp1[j]+cm[i+j-1];
            if (j>0) v2-=cm[j-1];
            dp2.push_back(mx(v1,v2));
        }
        dp1={};
        for(int j=0;j<dp2.size();j++){
            //cout<<dp2[j]<<" ";
            dp1.push_back(dp2[j]);
        }
        //cout<<'\n';
    }
    cout<<dp1[0]<<'\n';
    return 0;
}