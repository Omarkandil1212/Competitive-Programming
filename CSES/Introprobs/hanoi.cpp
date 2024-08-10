#include <iostream>
using namespace std;
typedef long long int ll;
#include <vector>

vector<int> hanoi(int n,int st,int m,int e){
    vector<int> ans = vector<int>();
    if(n==1){
        ans.push_back(st);
        ans.push_back(e);
        return ans;
    }
    vector<int> tmp = hanoi(n-1,st,e,m);
    for(int i=0;i<tmp.size();i++){
        ans.push_back(tmp[i]);
    }
    ans.push_back(st);
    ans.push_back(e);
    vector<int> tmp2 = hanoi(n-1,m,st,e);
    for(int i=0;i<tmp2.size();i++){
        ans.push_back(tmp2[i]);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> ans = hanoi(n,1,2,3);
    cout<<ans.size()/2<<endl;
    int i=0;
    while (i<ans.size()){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
        i+=2;
    }
    return 0;
}