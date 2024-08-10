#include <iostream>
using namespace std;
#include <vector>
typedef long long int ll;
vector<vector<ll>> subs(vector<ll> s){
    vector<vector<ll>> ans=vector<vector<ll>>();
    int n =s.size();
    if (n==1){
        vector<ll> emp=vector<ll>();
        ans.push_back(emp);
        ans.push_back(s);
        return ans;
    }
    vector<vector<ll>> tmp = subs({s.begin(),s.end()-1});
    for(ll i=0;i<tmp.size();i++){
        ans.push_back(tmp[i]);
        ans.push_back(tmp[i]);
        ans[ans.size()-1].push_back(s[n-1]);
    }
    return ans;




}

int main(){
    int n;
    ll x,sm;
    sm=0;
    cin>>n;
    vector<ll> el=vector<ll>();
    for(int i=0;i<n;i++){
        cin>>x;
        sm+=x;
        el.push_back(x);
        
        
    }
    ll cur=0;
    ll res=-1;
    ll dif=0;
    vector<vector<ll>> ans=subs(el);
    for(int j=0;j<ans.size();j++){
        cur=0;
        for(int k=0;k<ans[j].size();k++){
            cur+=ans[j][k];
        }
        if (cur != sm && cur!=0){
            dif = sm-2*cur;
            if (dif<0) dif=-dif;
            if (dif<res || res==-1) res=dif;
        }
    }
    if (n==1) cout<<el[0]<<endl;
    else cout<<res<<endl;
    return 0;

}