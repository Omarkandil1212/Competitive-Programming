#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    bitset<100001> dp;
    ll n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        dp = dp | (dp<<a);
    }
}