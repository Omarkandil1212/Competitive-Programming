#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int cur,mx=1;
    char nw,prev;
    prev=s[0];
    cur=1;
    for(int i=1;i<n;i++){
        nw=s[i];
        if (nw==prev){
            cur+=1;
        }
        else{
            if (cur>mx) mx=cur;
            cur=1;
        }
        if (i==n-1){
            if (cur>mx) mx=cur;
        }
        prev=nw;
    }
    cout<<mx<<endl;
    return 0;
}