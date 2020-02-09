#include<bits/stdc++.h>
using namespace std;
#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define cases ll t;cin>>t;while(t--)
#define lld long double
#define mod 100000000007
#define f1(a,b) for(ll i=a; i<b; i++)
#define f3(a,b) for(ll k=a; k<b; k++)
#define f2(a,b) for(ll j=a; j<b; j++)
#define f4(a,b) for(ll l=a; l<b; l++)
#define f1n(a,b) for(ll i=a; i>b; i--)
#define mp make_pair
#define pb push_back
#define mem(v) memset((v),0,sizeof(v));
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define sll set<ll>
#define vll vector<ll>
#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod
#define ad(a,b)  (a%mod+b%mod+mod)%mod
#define cases ll t;cin>>t;while(t--)
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
ll max(ll a,ll b)
{
    if(a>b)
        return a;
    return b;
}
ll min(ll a,ll b)
{
    if(a<b)
        return a;
    return b;
}
#define maxi(a,b,c) max(a,max(b,c))
#define mini(a,b,c) min(a,min(b,c))
ll powered(ll x,ll y)  
{  
    ll temp;  
    if(y == 0)  
        return 1;  
    temp = powered(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
}
void solve(){
    ll n;
    cin>>n;
}
int main(){
    fast;
        solve();
    return 0;
}
