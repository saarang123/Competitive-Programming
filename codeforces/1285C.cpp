#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <ll, greater <ll> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
vector<pair<ll,ll> > pri;

void prime(ll x)
{
    for(ll i=1; i<=sqrt(x); i++)
    {
        if(x%i==0)
        {
            pri.pb(mp(i,1ll*x/i));
        }
    }
}

ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j;
    cin >> n;
    prime(n);
    ll a1=1,a2=n;
    for(i=0; i<pri.size(); i++)
    {
        ll p1=pri[i].f, p2=pri[i].ss;
        if((p1*p2)/gcd(p1,p2)==n)
        {

            if(max(p1,p2)<max(a1,a2))
            {
                a1 = p1;a2=p2;
            }
        }
    }
    cout << a1 << " " << a2 << "\n";
    return 0;
}
