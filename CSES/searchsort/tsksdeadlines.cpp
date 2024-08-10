#include <bits/stdc++.h>
using namespace std;
typedef long int ll;

int main(){
    ll n,x,ans,v,cmsm;
    ans=0;
    cin>>n;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>x; cin>>v;
        ans+=v;
        arr.push_back(x);
    }
    cmsm=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        cmsm+=arr[i];
        ans-=cmsm;
    }
    cout<<ans<<'\n';
    return 0;
}