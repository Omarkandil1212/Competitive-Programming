#include <iostream>
using namespace std;
typedef long long int ll; 
#include <map>
int main(){
    string s,ans;
    cin>>s;
    ans=s;
    map<char,ll> freq= map<char,ll>();
    ll n = s.size();
    for(int i=0;i<n;i++){
        if (freq.find(s[i])==freq.end()) freq.insert({s[i],1});
        else freq[s[i]]++;
    }
    bool cn=true;
    bool one=false;
    char cone=' ';
    for(auto it=freq.begin();it!=freq.end();it++){
        if (it->second%2==1){
            if (one){
                cn=false;
            }
            else{
                cone=it->first;
                one=true;
            }
        }
    }
    ll trav=0;
    ll cur=0;
    if (cn){
        for(auto it=freq.begin();it!=freq.end();it++){
            if (it->second%2==0){
                cur=it->second;
                while(cur>0){
                    ans[trav]=it->first;
                    ans[n-trav-1]=it->first;
                    trav++;
                    cur-=2;
                }
                
            }
        }
        if(one){
            cur=freq[cone];
            while(cur>1){
                    ans[trav]=cone;
                    ans[n-trav-1]=cone;
                    trav++;
                    cur-=2;
                }
            ans[trav]=cone;
        }
        cout<<ans<<endl;
    }
    else{
        cout<<"NO SOLUTION"<<endl;
    }


    return 0;
}