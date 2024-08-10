#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;
    map<ll, int> freq=map<ll,int>();
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if (freq.find(x)==freq.end()) freq.insert({x,1});
    }
    cout<<freq.size()<<'\n';
    return 0;
}