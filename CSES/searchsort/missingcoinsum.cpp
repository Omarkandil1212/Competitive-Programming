#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,a,cur;
    cin>>n;
    vector<ll> arr={};
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(),arr.end());
    cur=1;
    if (arr[0]==1){
        for(int i=1;i<n;i++){
            if (arr[i]<=cur+1){
                cur+= arr[i];
                if (i==n-1) cur++;
            }
            else{
                cur++;
                break;
            }
            
        }
    } 
    cout<<cur<<'\n';
    
}