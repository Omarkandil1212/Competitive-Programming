#include <iostream>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int cur,prev,ans;
    ans=0;
    cin>>prev;
    n-=1;
    while(n--){
        cin>>cur;
        if (cur>=prev) prev=cur;
        else ans+=prev-cur;
    }
    cout<<ans<<endl;
    return 0;
}