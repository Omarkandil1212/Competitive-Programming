#include <iostream>
using namespace std;
int main(){
    long long int n,x;
    cin>>n;
    long long int sum=0;
    long long int target = (n*(n+1))/2;
    n-=1;
    while(n--){
        cin>>x;
        sum+=x;
    }
    cout<<target-sum<<endl;
   
    
}