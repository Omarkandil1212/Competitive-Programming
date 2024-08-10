#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if (n==1) cout<<1<<endl;
    else if (n<4) cout<<"NO SOLUTION"<<endl;
    else if (n==4) cout<<3<< " "<<1<<" "<<4<<" "<<2<<endl;
    else{
        int x =n-1;
        while (n>=1){
            cout<<n<<" ";
            n-=2;
        }
        while (x>=1){
            cout<<x<<" ";
            x-=2;
        }
        cout<<endl;
    }
    return 0;
}