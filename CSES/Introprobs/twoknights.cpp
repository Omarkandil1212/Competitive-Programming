#include <iostream>
using namespace std;
int main(){
    long long int n,j;
    cin>>n;
    for(int i=1;i<=n;i++){
        j=i*i;
        cout<<(j*(j-1)/2) - ((i-1)*(i-2)*4)<<endl;
    }
    return 0;
}