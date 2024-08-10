#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct trienode{
    bool eow;
    trienode* ch[2];
    trienode(){
        eow=false;
        for(int i=0;i<2;i++) ch[i]=NULL;
    }
};

class Trie {
public:
trienode* root;
int depth=31;
    Trie() {
        root= new trienode();
    }
    
    void insert(ll num) {
        bool va;
        trienode* cur=root;
        for(int i=depth-1;i>=0;i--){
            va= (num>>i) & 1;
            if (cur->ch[va]==NULL) cur->ch[va]=new trienode();
            cur=cur->ch[va];
        }
        cur->eow=true;
    }
    
    ll search(ll num){
        ll ans=0;
        bool va;
        trienode* cur=root;
        for(int i=depth-1;i>=0;i--){
            va= (num>>i)& 1;
            if (cur->ch[!va]!=NULL){
                ans+= pow(2,i);
                cur=cur->ch[!va];
            }
            else{
                cur=cur->ch[va];
            }
            
        }
        return ans;
    }
    
};
ll mx(ll a, ll b){
    if (a>b) return a;
    return b;
}

int findMaximumXOR(vector<int>& nums) {
    int n = nums.size();
    ll ans=0;
    Trie tr=Trie();
    for(int i=0;i<n;i++){
        tr.insert(nums[i]);
        ans=mx(ans, tr.search(nums[i]));
    }
    cout<<ans<<'\n';
    return ans;
}

int main(){
    vector<int> nums = {14};
    findMaximumXOR(nums);
    return 0;

}