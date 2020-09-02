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
int kmp(string pat,string txt){
    int m=pat.length(),n=txt.length(),ans=0;
    int lps[m];lps[0]=0;
    if(m>n) return 0;
    for(int i=1;i<m;i++){
        int j=lps[i-1];
        while(j!=0 && pat[i]!=pat[j]) j=lps[j-1];
        if(pat[i]==pat[j]){
            lps[i]=j+1;
        }else{
            lps[i]=0;
        }
    }
    for(int i=0,j=0;i<n;i++){
        if(txt[i]==pat[j]){
            if(++j==m){
                ans++;
                j=lps[j-1];
            }
        }else if(j>0){
            i--;
            j=lps[j-1];
        }
    }
    return ans;
}
void dijkstra(int src){
    set<pair<int,int> > setds;
    vector<int> dist(n);
    vector<int> path(n,-1);
    dist[src]=0;
    setds.insert(make_pair(0,src));
    while(!setds.empty()){
        pair<int,int> tmp= (*setds.begin());
        setds.erase(setds.begin());
        int u=tmp.second;
        for(auto &i:adj[u]){
            int v=i.first,cost=i.second;
            if(dist[u]+cost<dist[v]){
                if(dist[v]!=INF){
                    setds.erase(setds.find(make_pair(dist[v],v)));
                }
                dist[v]=dist[u]+cost;
                setds.insert(make_pair(dist[v],v));
                p[v]=u;
            }
        }
    }
    int t;
    vector<int> path;
    for(int i=t;i!=src;i=p[i]){
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
}
bool isValidPreorder(int pre[],int n){
    stack<int> dec_order;
    int root=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre[i]<root)
            return false;
        while(!s.empty()&&s.top()<pre[i]){
            root=s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}
struct node{
    int data,mn,mx;
};
bool isValidLevelOrder(int lvl[],int n){
    queue<node> lvl_order;
    node temp={lvl[0],INT_MAX,INT_MIN};
    int i=1;
    while(i!=n && !q.empty()){
        node check=lvl_order.front();
        lvl_order.pop();
        if(i<n && lvl[i]<check.data){
            node t1={lvl[i++],check.data,check.min};
            lvl_order.push(t1);
        }
        if(i<n && !q.empty()){
            node t2={lvl[i++],check.max,check.data};
            lvl_order.push(t2);
        }
    }
    if(i==n)
        return true;
    return false;
}
{
    int log[25];
    log[1]=0;
    for(int i=2;i<MAXN;i++)
        log[i]=log[i/2]+1;
    int st[n][25];
    for(int i=0;i<n;i++)
        st[i][0]=ar[i];
    for(int j=1;j<=25;j++)
        for(int i=0;i+(1<<j)<=n;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    int l,r,sum=0;
    for(int i=k;i>=0;i--)
        if(1<<j<=(l-r+1)){
            sum+=st[l][j];
            l+=(1<<j);
        }
    int k=log(l-r+1);
    ans=min(st[l][k],st[r-(1<<k)+1][k]);
}
