#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


const ll md=pow(10,9)+7; 
struct Matrix
{
    int n;
    vector<vector<ll>> mat;
    Matrix(int pn): n(pn) // pn*pn matrix
    {
        mat=vector<vector<ll>>(n,vector<ll>(n,0));
    }
    void fill(vector<vector<ll>>& gr) // problem specific how to fill matrix
    {
        for(int i=0;i<n;i++){
            for(int j=0;j<gr[i].size();j++){
                mat[i][gr[i][j]]=1;
            }
        }
    }
    vector<ll>& operator [](ll ind)
    {
        return mat[ind];
    }
    Matrix operator *(Matrix& rhs)
    {
        Matrix res(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int l=0;l<n;l++){
                    res[i][j]+= (mat[i][l]* rhs[l][j])%md; // include mod if needed.
                    res[i][j]%=md;
                }
            }
        }
        return res;
    }
    void makeIdentity()
    {
        for(int i=0;i<n;i++) mat[i][i]=1;
    }
    ll sumAllEntries()
    {
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=mat[i][j];
                ans%=md;
            }
        }
        return ans;
    }

    Matrix operator^(ll expo)
    {
        Matrix res(n);
        Matrix cur=*this;
        res.makeIdentity(); // not always want the identity initially
        while(expo)
        {
            if (expo%2)
            {
                res = res*cur;
            }
            cur=cur*cur;
            expo/=2;
        }
        return res;
    }
    

};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n,m,a,b,k; 
    cin>>n>>m>>k;
    Matrix mx(n);
    vector<vector<ll>> gr(n,vector<ll>());
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--; b--;
        gr[a].push_back(b);
    }
    mx.fill(gr);
    Matrix res=mx^k;
    cout<<res.sumAllEntries()<<'\n';
 
    return 0;
}