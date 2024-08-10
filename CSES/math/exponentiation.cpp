#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int md=pow(10,9)+7;
ll expo(ll a, ll b){
    if (b==0) return 1;
    if (b%2==1) return (a*expo(a,b-1)%md)%md;
    else{
        ll cur= expo(a,b/2);
        cur%=md;
        return (cur*cur)%md;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a; cin>>b;
        cout<<expo(a,b)<<'\n';
    }
    return 0;
}