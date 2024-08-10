#include <iostream>
using namespace std; 
#include <vector>

vector<string> gray(int n){
    vector<string> ans = vector<string>();
    string t;
    if (n==1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }

    vector<string> tmp = gray(n-1);

    
    for(int i=0;i<tmp.size();i++){
        t="0";
        t+=tmp[i];
        ans.push_back(t);
    }
    for(int i=tmp.size()-1;i>=0;i--){
        t="1";
        t+=tmp[i];
        ans.push_back(t);
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    
    
    vector<string> ans = gray(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    
    return 0;
}