#include <iostream>
using namespace std; 
#include <vector>
#include<string>
#include <map>

vector<string> permut(string s){
    int n =s.size();
    vector<string> ans=vector<string>();
    if (n==1){
        ans.push_back(s);
        return ans;
    }
    vector<string> tmp = permut(s.substr(0,n-1));
    string cur;
    for(int i=0;i<tmp.size();i++){
        cur=tmp[i];
        ans.push_back(s[n-1]+cur);
        for(int j=0;j<cur.size();j++){
            if (cur[j]!=s[n-1]){
                ans.push_back(cur.substr(0,j+1) + s[n-1]+cur.substr(j+1,n-j-2));
            }
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    vector<string> ans = permut(s);
    
    map<string,int> freq=map<string,int>();
    for(int i=0;i<ans.size();i++){
        if (freq.find(ans[i])==freq.end()){
            freq.insert({ans[i],1});
        }
    }
    cout<<freq.size()<<endl;
    for(auto it=freq.begin();it!=freq.end();it++){
        cout<<it->first<<endl;
    }
    return 0;
}