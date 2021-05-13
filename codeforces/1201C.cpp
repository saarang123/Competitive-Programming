#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> a;

bool movie(ll x, int n, int k)
{
    ll ans = 0;
    for(int i=n/2; i<n; i++)
    {
        if(x-a[i]>0) ans+=x-a[i];
        if(ans>k) return false;
    }
    if(ans<=k) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> k;
    for(i=0; i<n; i++)
    {
        cin >> j;
        a.pb(j);
    }
    sort(a.begin(),a.end());
    ll m1=1, m2=2e9;
    while(m1!=m2)
    {
        ll x = (m1+m2+1)/2;
        if(movie(x,n,k))
        {
            m1 = x;
        }
        else
        {
            m2 = x-1;
        }
    }
    cout << m1 << "\n";
    return 0;
}
