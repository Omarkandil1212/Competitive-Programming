#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k;
    ll x;
    ll ans=0;
    cin>>n; cin>>k;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>x; arr.push_back(x);
    }
    unordered_map<ll,int> freq;
    int ind=0;
    for(int i=0;i<n;i++){
        if (freq.find(arr[i])==freq.end()) freq.insert({arr[i],1});
        else freq[arr[i]]++;
        while (freq.size()>k){
            ans+=i-ind;
            freq[arr[ind]]--;
            if (freq[arr[ind]]==0) freq.erase(arr[ind]);
            ind++;
        }
    }
    ll rem=(n-ind);
    ans+= (rem*(rem+1ll))/(2ll);
    cout<<ans<<'\n';



    return 0;
}