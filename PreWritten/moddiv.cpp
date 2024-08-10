#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll md=pow(10,9)+7;
ll mod_pow(ll a, ll b){
    ll res=1;
    while(b){
        if (b&1) res= (res*a)% md;
        a=(a*a) %md;
        b>>=1;
    }
    return res;
}
ll mod_div(ll a, ll b){
    return (a*mod_pow(b,md-2))%md;
}