#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,w,x;
    cin>>n;
    cin>>w;
    vector<ll> children = vector<ll>();
    for(int i=0;i<n;i++){
        cin>>x;
        children.push_back(x);
    }
    sort(children.begin(),children.end());
    ll ans=0;
    ll i,j;
    i=0;j=n-1;
    while(i<j){
        if (children[i]+children[j]<=w){
            i++;
            j--;
            ans++;
        }
        else{
            j--;
        }
    }
    ans+= n-(2*ans);
    cout<<ans<<'\n';

    return 0;
}