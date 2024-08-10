#include <iostream>
using namespace std;
#include <cmath>
typedef long long int ll;
#include <vector>
int main(){
    ll m = pow(10,9)+7;
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
    for(ll i=1;i<=x;i++){
        for (int j=0;j<n;j++){
            if (i>=cns[j]){
                arr[i]+=arr[i-cns[j]];
                arr[i]=arr[i]%(m);
            }
        }
    }
    //for(int i=0;i<=x;i++){
    //    cout<<arr[i]<<" ";
    //}
    cout<<arr[x]<<endl;
    return 0;
}