#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x;
    cin>>n;
    int mx=pow(10,6)+1;
    vector<int> cnt;
    for(int i=0;i<mx;i++){
        cnt.push_back(1);
    }
    for(int i=2;i<mx;i++){
        for(int j=i;j<mx;j+=i){
            cnt[j]++;
        }
    }
    for(int i=0;i<n;i++){
        cin>>x;
        cout<<cnt[x]<<'\n';
    }

    return 0;
}