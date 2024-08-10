#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t,n,ones,twos,prv;
    cin>>t;
    const ll m = pow(10,9)+7;
    while(t--){
        cin>>n;
        ones=1;
        twos=1;
        for(int i=2;i<=n;i++){
            prv=ones;
            ones= 4*ones + twos;
            twos=2*twos + prv;
            twos%=m;
            ones%=m;
        }
        cout<<(ones+twos)%m<<'\n';
    }
    return 0;
}