#include <iostream>
using namespace std;
#include <cmath>
int main(){
    long long int n,ans;
    cin>>n;
    ans=1;
    for(int i=0;i<n;i++){
        ans = ans*2;
        ans=ans%((int)pow(10,9) +7);
    }
    cout<<ans<<endl;
    return 0;
}