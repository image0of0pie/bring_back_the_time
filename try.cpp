//
//  try.cpp
//  
//
//  Created by Sarvajit Kumar on 19/10/19.
//finding out minimum number of cuts required to split a char sequence into palindromic subsets
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define mod 1000000007
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f1(a,b) for(ll i=a; i<b; i++)
#define f3(a,b) for(ll k=a; k<b; k++)
#define f2(a,b) for(ll j=a; j<b; j++)
#define mp make_pair
#define pb push_back
#define mem(v) memset((v),0,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define cases ll t;cin>>t;while(t--)
int main()
{
    fast
    char s[100];
    cin>>s;
    ll dp[101][101];
    mem(dp);
    f1(1,strlen(s)+1)
    {
        f2(1,i+1)
        {
            if((i-j)>2)
            {
                if((s[i-1]==s[j-1])&&dp[i-1][j+1])
                    dp[i][j]=dp[j][i]=1;
            }
            else
            {
                if(s[i-1]==s[j-1])
                    dp[i][j]=dp[j][i]=1;
            }
        }
    }

    /*f1(1,strlen(s)+1)
    {
        f2(1,i+1)
        cout<<dp[i][j]<<" ";
        cout<<"\n";
    }*/
    ll store[101];
    f1(0,strlen(s)+1)
    store[i]=1e9;
    f1(1,strlen(s)+1)
    {
        if(dp[1][i])
            store[i]=0;
        else
        {
            f2(1,i+1)
                if(dp[i][j])
                    store[i]=min(store[i],store[j-1]+1);
        }
    }
    cout<<store[strlen(s)]<<endl;
    return 0;
}
