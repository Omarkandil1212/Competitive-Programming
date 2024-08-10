#include <iostream>
using namespace std;
typedef long long int ll; 
int main(){
    ll t,c,c1,c2;
    bool ans;
    cin>>t;
    while(t--){
        cin>>c1;
        cin>>c2;
        c=c1+c2;
        ans = (c%3==0 && c1<=2*c2 && c2<=2*c1);
        if (ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}