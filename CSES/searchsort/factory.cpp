#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool bs(vector<ll>&arr, ll n, ll v,ll t){
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+= (v/arr[i]);
        if (ans>=t) return true;
    }
    return ans>=t;
}

int main(){
    ll n,t,a;
    cin>>n; cin>>t;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    //sort(arr.begin(),arr.end());
    ll lo=0;
    ll hi = pow(10,18);
    ll md;
    ll ans=-1;
    while(lo<=hi){
        md=(lo+hi)/2;
        if (bs(arr,n,md,t)){
            ans=md;
            hi=md-1;
        }
        else lo=md+1;
    }
    cout<<ans<<'\n';
    //cout<<2/2550000000<<'\n';

    return 0;
}