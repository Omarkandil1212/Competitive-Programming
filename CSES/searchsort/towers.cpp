#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,k;
    cin>>n;
    multiset<ll> freq;
    for(int i=0;i<n;i++){
        cin>>k;
        if (freq.size()==0 || freq.lower_bound(k+1)==freq.end()){
            freq.insert(k);
        }
        else{
            freq.erase(freq.lower_bound(k+1));
            freq.insert(k);
        }
    }
    cout<<freq.size()<<'\n';


    return 0;
}