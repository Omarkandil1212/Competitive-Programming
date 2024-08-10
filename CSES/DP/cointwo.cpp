#include <iostream>
using namespace std;
#include <cmath>
typedef long long int ll;
#include <vector>
int main(){
    const ll m = pow(10,9)+7;
    ll n,x,c;
    cin>>n;
    cin>>x;
    ll arr[x+1];
    vector<ll> cns=vector<ll>();
    for(int i=0;i<n;i++){
        cin>>c;
        cns.push_back(c);
    }
    for(ll i=0;i<=x;i++){
        arr[i]=0;
    }
    arr[0]=1;
    for (int i=0;i<n;i++){
        for(ll j=0;j<x;j++){
            if (arr[j] && j+cns[i]<=x) {
                arr[j+cns[i]]+=arr[j];
                arr[j+cns[i]]%=m;
            } 
        }
    }
    cout<<arr[x]<<'\n';


    return 0;
}