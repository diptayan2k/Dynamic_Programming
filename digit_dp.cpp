/* -----------------Digit Dynamic Programming---------------*/

Problem link: https://www.hackerearth.com/problem/algorithm/playing-with-digits-4e25844f/description/

#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
#define f(i,a,b) for(ll i=a;i<=b;i++)
#define g(i,a,b) for(ll i=a;i>=b;i--)
#define F first
#define vv vector
#define S second
#define mp make_pair
#define pb push_back
#define mh make_heap
#define ph push_heap
#define pq priority_queue
using namespace std;
bool prime[501];

vector<ll> v;

void digit(ll a)
{
    if(a==0) v.pb(0);
    while(a!=0)
     {
        v.pb(a%10);
        a/=10;
    }
}


void SieveOfEratosthenes(ll n)
{

    memset(prime, true, sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for (ll p=2; p*p<=n; p++)
    {

        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

}
ll d;
ll dp[15][201][4001][2];
ll digitdp(ll i, ll sum,ll r, ll t)
{
    if(i==-1)
    {
        if(prime[sum]&&r%d==0) { return 1;
        }
         return 0;
    }

    if(dp[i][sum][r][t]!=-1&&t==0) {return dp[i][sum][r][t]; }

    ll k=(t)?v[i]:9;
    ll res=0;
    f(j,0,k)
    {
        ll nt=0;
        if(j==v[i]) nt=t;
        res+=digitdp(i-1,sum+j,(((r*10)+j)%d),nt);
        //cout<<i<<" "<<j<<" "<<res<<endl;
    }
    dp[i][sum][r][t]=res;
    return res;



}

bool check(ll n)
{
    ll sum=0;
    while(n)
    {
        sum+=n%10;
        n=n/10;
    }
    if(prime[sum]) return true;
    return false;
}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
SieveOfEratosthenes(500);
ll a,b;
cin>>a>>b>>d;
if(d<=4000){

memset(dp,-1,sizeof(dp));
digit(b);
ll ans1=digitdp(v.size()-1,0,0,1);


v.clear();
memset(dp,-1,sizeof(dp));
digit(a-1);
ll ans2=digitdp(v.size()-1,0,0,1);

cout<<ans1-ans2;
}
else{
    ll res=0;
    ll start=(a/d)*d;
       if(start<a)start+=d;
       for(ll i=start;i<=b;i+=d)
       {
           if(check(i)) res++;
       }
       cout<<res;
}
}





