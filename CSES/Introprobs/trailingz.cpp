#include <iostream>
using namespace std;
typedef long long int ll; 
int main(){
    long long int n;
    cin>>n;
    ll ans=0;
    ll p=5;
    while(p<=n){
        ans+=n/p;
        p=p*5;
    }
    cout<<ans<<endl;
    return 0;
}