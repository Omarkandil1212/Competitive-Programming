#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct LRUnode{
    int k; int v;
    LRUnode* nxt;
    LRUnode*prv; LRUnode*loc;
    LRUnode(){
        nxt=NULL;
        prv=NULL;
        loc=NULL;
    }
    LRUnode(int k1, int v1){
        nxt=NULL;
        prv=NULL;
        loc=NULL;
        v=v1;
        k=k1;
    }
};

class LRUCache {
public:
    LRUnode* ls;
    LRUnode* ms;
    unordered_map<int, LRUnode*> mp=unordered_map<int,LRUnode*>();
    int n,sz;
    LRUCache(int capacity) {
        n=capacity;
        sz=0;
        ls=new LRUnode();
        ms=new LRUnode();
    }
    
    int get(int key) {
        if (mp.find(key)==mp.end())return -1;
        LRUnode* cur=mp[key];
        if (cur->nxt!=ms){
            if (sz>1 || n>1){
                cur->prv->nxt=cur->nxt;
                cur->nxt->prv=cur->prv;
                ms->prv->nxt=cur;
                cur->prv= ms->prv;
                cur->nxt=ms;
                ms->prv=cur;
            }
        }
        mp[key]=cur;
        return cur->v;
    }
    
    void put(int key, int value) {
        bool th;
        th=false;
        LRUnode* cur=new LRUnode(key,value);
        if (mp.find(key)!=mp.end()){
            cur= mp[key];
            cur->v=value;
            th=true;
            if (cur->nxt!=ms){
                cur->prv->nxt=cur->nxt;
                cur->nxt->prv=cur->prv;
                ms->prv->nxt=cur;
                cur->prv=ms->prv;
                cur->nxt=ms;
                ms->prv=cur;
            }
        }
        else {
            mp.insert({key,cur});
            if (sz<n){
                sz++;
                if (ms->prv==NULL){
                    ms->prv=cur; cur->nxt=ms;
                    ls->nxt=cur; cur->prv=ls;
                }
                else{
                    ms->prv->nxt=cur;
                    cur->prv=ms->prv;
                    cur->nxt=ms;
                    ms->prv=cur;
                }
            }
            else{
                if (n>1){
                    mp.erase(ls->nxt->k);
                    ls->nxt->nxt->prv=ls;
                    ls->nxt=ls->nxt->nxt;
                    ms->prv->nxt=cur;
                    cur->prv=ms->prv;
                    cur->nxt=ms;
                    ms->prv=cur;

                }
                else{
                    mp.erase(ls->nxt->k);
                    ls->nxt=cur;
                    cur->prv=ls;
                    cur->nxt=ms;
                    ms->prv=cur;
                }
            }
        }
        mp[key]=cur;
    }
};
