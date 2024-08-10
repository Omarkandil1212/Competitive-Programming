#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// other algos:
// to find lcs of 2 strings, put them together as s1+$+s2+# and find lcp

void countingSort(vector<int>& suf, vector<int>& cs, int n)
{
    vector<int> cnt(n);
    for(int i=0;i<n;i++){
        cnt[cs[i]]++;
    }
    for(int i=1;i<n;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    vector<int> newA(n);
    for(int i=n-1;i>=0;i--)
    {
        newA[--cnt[cs[suf[i]]]]=suf[i];
    }
    swap(newA,suf);
}

struct SuffixArray
{
    ll n; string s;
    vector<int> suffix; // of length original string length + 1 with first index being for empty string ($)
    vector<int> lcp;
    SuffixArray(int pn, string& ps)
    {
        n=pn+1; // n is length of original string +1 for the $
        s=ps;
        s+='$';
        suffix=vector<int>(n);
        lcp=vector<int>(n-1);
        buildSuffix();

    }
    void buildSuffix()
    {
        // first pass for k=0
        vector<pair<char,int>> ps;
        for(int i=0;i<n;i++) ps.push_back({s[i],i});
        sort(ps.begin(),ps.end());
        int ind=0;
        vector<int> cs(n);
        cs[ps[0].second]=0;
        suffix[0]=ps[0].second;
        for(int i=1;i<n;i++){
            if (ps[i].first!=ps[i-1].first) ind++;
            cs[ps[i].second]=ind;
            suffix[i]=ps[i].second;
        }
        int k=0;
        pair<int,int> p1,p2;
        // next iterations
        while( (1<<k) < n)
        {
            for(int i=0;i<n;i++) suffix[i] = (suffix[i]- (1<<k) +n)%n;
            countingSort(suffix,cs,n);
            vector<int> newC(n);
            newC[suffix[0]]=0;
            ind=0;
            for(int i=1;i<n;i++)
            {
                p1= { cs[suffix[i - 1]], cs[(suffix[i - 1] + (1<<k)) % n] };
			    p2 = { cs[suffix[i]], cs[(suffix[i] + (1<<k)) % n] };
                if (p1!=p2) ind++;
                newC[suffix[i]]=ind;
            }
            cs = move(newC);
            k++;
        }

        // LCP
        int lc=0; int ind2;
        for(int i=0;i<n-1;i++)
        {
            ind=i+lc;
            ind2=suffix[cs[i]-1]+lc; // in the end, cs will have the index of i in the suffix array
            while(ind<n-1 && ind2<n-1 && s[ind]==s[ind2])
            {
                ind++;
                ind2++;
                lc++;
            }
            lcp[cs[i]-1]=lc;
            lc=max(lc-1,0);
        }
    }

    ll countSubstrings()
    {
        ll ans= (n*(n-1))/2;
        for(auto x:lcp) ans-=x;
        return ans;
    } 
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin>>s;
    int n = s.size();
    SuffixArray sf(n,s);
    cout<<sf.countSubstrings()<<'\n';


    return 0;
}