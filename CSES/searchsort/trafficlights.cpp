#include <bits/stdc++.h>
using namespace std;
typedef long int ll;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,x,a,x1,x2,x3,x4,x5;
    cin>>x; cin>>n;
    set<ll> pos;
    //map<ll,ll> neg=map<ll,ll>();
    multiset<ll,greater<ll>> dif;
    pos.insert(x);
    pos.insert(0);
    pos.insert(-x);
    //neg.insert({0,1});
    dif.insert(x);
    for(int i=0;i<n;i++){
        cin>>a;
        x1=*pos.lower_bound(a);
        x2=-*pos.lower_bound(-a);
        //cout<<a<< " "<<x1<<" "<<x2<<'\n';
        x3=x1-x2;
        x4=x1-a;
        x5=a-x2;
        dif.erase(dif.find(x3));
        dif.insert(x4);
        dif.insert(x5);
        cout<<*dif.begin()<<' ';
        pos.insert(a);
        pos.insert(-a);
    }
    cout<<'\n';
    


    return 0;
}