#include <iostream>
using namespace std;
int main(){
    long long int n,trgt,cnt,sm;
    cin>>n;
    if ((n*(n+1)/2)%2==0 ){
        cout<<"YES"<<endl;
        bool arr[n];
        for(int i=0;i<n;i++)arr[i]=false;
        
        trgt=(n*(n+1))/4;
        cnt=0;
        sm=0;
        long long int i=n;
        while(sm!=trgt){
            if ((sm+i)<=trgt){
                sm+=i;
                arr[i-1]=true;
                cnt+=1;
            } 
            i-=1;
        }
        cout<<cnt<<endl;
        for(int i=0;i<n;i++){
            if (arr[i]){
                cout<<i+1<<" ";
            }

        }
        cout<<endl;
        cout<<n-cnt<<endl;
        for(int i=0;i<n;i++){
            if (!arr[i]){
                cout<<i+1<<" ";
            }

        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}