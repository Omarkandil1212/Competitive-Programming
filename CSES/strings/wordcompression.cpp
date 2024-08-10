#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct trienode{
    bool eow;
    trienode* ch[26];
    trienode(){
        eow=false;
        for(int i=0;i<26;i++) ch[i]=NULL;
    }
};

struct trie {

    trienode* root;
    trie() {
        root= new trienode();
    }
    
    void insert(string word) {
        trienode* cur=root;
        for(int i=0;i<word.size();i++){
            if (cur->ch[word[i]-'a'] == NULL) cur->ch[word[i]-'a']=new trienode();
            cur=cur->ch[word[i]-'a'];
        }
        cur->eow=true;
    }
    
    bool search(string word) {
        trienode* cur=root;
        for(int i=0;i<word.size();i++){
            if (cur->ch[word[i]-'a'] == NULL) return false;
            cur=cur->ch[word[i]-'a'];
        }
        return cur->eow;
    }
    
    bool startsWith(string prefix) {
        trienode* cur=root;
        bool ans=true;
        for(int i=0;i<prefix.size();i++){
            if (cur->ch[prefix[i]-'a'] == NULL) return false;
            cur=cur->ch[prefix[i]-'a'];
        }
        return true;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int md=pow(10,9)+7;
    string s,s1;
    int n;
    trie tr;
    cin>>s; cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1;
        tr.insert(s1);
    }
    int m=s.size();
    vector<ll> dp(m+1,0);
    trienode* t;
    dp[0]=1;
    for(int i=0;i<m;i++){
        t=tr.root;
        for(int j=i;j<m;j++){
            //cout<<i<<" "<<j<<" "<<t->eow<<"\n";
            if (t->ch[s[j]-'a']==NULL){
                break;
            }else{
                t=t->ch[s[j]-'a'];
                if (t->eow){
                    dp[j+1]+=dp[i];
                    dp[j+1]%=md;
                }
            }
        }
    }
    //for(int i=0;i<=n;i++) cout<<dp[i]<<' ';
    cout<<dp[m]<<'\n';
    return 0;
}