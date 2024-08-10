#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
 
ll count(ll a)
{
    ll dig=0;
    ll b= a;
    string s="";
    if (a==0) return 1;
    while(b)
    {
        dig++;
        s+= (b%10)+'0';
        b/=10;
    }
    if (dig==1) return a+1;
    reverse(s.begin(),s.end());
    //cout<<dig<<' '<<s<<'\n';
    vector<vector<vector<ll>>> dp(dig+1,vector<vector<ll>>(10,vector<ll>(3,0)));
    ll ans=1;
    for(int k=1;k<10;k++)
    {
        if (s[0]-'0' == k)
        {
            dp[1][k][1]=1;
        }
        else if (s[0]-'0'>k)
        {
            dp[1][k][2]=1;
        }
        else dp[1][k][0]=1;
    }
    for(int i=1;i<dig;i++)
    {
        for(int k=0;k<10;k++)
        {
            for(int j=0;j<3;j++)
            {
                if (dp[i][k][j]==0) continue;
                for(int o=0;o<10;o++)
                {
                    if (o==k) continue;
                    if (j==1)
                    {
                        if (o==s[i]-'0')
                        {
                            dp[i+1][o][1]+=dp[i][k][j];
                            //cout<<i<<' '<<k<<' '<<o<<'\n';

                        } 
                        else if (o<s[i]-'0')
                        {
                            dp[i+1][o][2]+=dp[i][k][j];
                            //cout<<i<<" c "<<k<<' '<<o<<'\n';
                        }
                        else
                        {
                            if(i+1<dig)dp[i+1][o][0]+=dp[i][k][j];
                        }
                    }
                    else if (j==2)
                    {
                        dp[i+1][o][2]+=dp[i][k][j];
                    }
                    else
                    {
                        if (i+1<dig)
                        {
                            dp[i+1][o][0]+=dp[i][k][j];
                        }
                    }
                }
            }
        }
    }
   for(int i=1;i<=dig;i++)
   {
        for(int j=0;j<10;j++)
        {
            ans+=dp[i][j][0];
            ans+=dp[i][j][1];
            ans+=dp[i][j][2];
            //if(i==1)cout<<j<<' '<<ans<<'\n';
        }
        //cout<<ans<<'\n';
   }
    
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a,b;
    cin>>a>>b;
    if (b==0) cout<<1<<'\n';
    else
    {
        ll ans = count(b);
        if (a>0)
        {
            ans-= count(a-1);
        }
        cout<<ans<<'\n';
    }


    return 0;
}