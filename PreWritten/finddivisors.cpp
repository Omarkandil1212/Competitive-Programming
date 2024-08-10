#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    vector<ll> factors={};
    ll n;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            factors.push_back(i);
            if(i!=n/i) factors.push_back(n/i);
        }
    }
    return 0;
}