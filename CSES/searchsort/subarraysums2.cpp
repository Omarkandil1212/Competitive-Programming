#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,k,x;
    cin>>n; cin>>k;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>x; arr.push_back(x);
    }
    map<ll,ll> freq;
    ll cmsm=0,ans=0;
    for(int i=0;i<n;i++){
        cmsm+=arr[i];
        if (freq.find(cmsm-k)!=freq.end()){
            ans+=freq[cmsm-k];
        }
        if (freq.find(cmsm)==freq.end()) freq.insert({cmsm,1});
        else freq[cmsm]++;
    }
    if (freq.find(k)!=freq.end()) ans+=freq[k];
    cout<<ans<<'\n';
    return 0;
}
