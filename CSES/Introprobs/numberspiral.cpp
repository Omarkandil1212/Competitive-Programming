#include <iostream>
using namespace std;
int main(){
    long long int t,x,y,bef;
    cin>>t;
    while(t--){
        cin>>y;
        cin>>x;
        if (y>=x){
            
            if (y%2==0){
                cout<< y*y - x+1<<endl;
            }
            else{
                bef = (y-1)*(y-1);
                cout<<bef+x<<endl;
            }

        }
        else{
            if (x%2!=0){
                cout<< x*x - y+1<<endl;
            }
            else{
                bef = (x-1)*(x-1);
                cout<<bef+y<<endl;
            }
        }
    }
    return 0;
}