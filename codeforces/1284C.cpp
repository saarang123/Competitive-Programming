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

void solve() {
    ll n,i,j,t,k,m;
    cin >> n >> m;
    ll fact[n+1];
    fact[0] = 1;
    for(i=1; i<=n; i++)
    {
        fact[i] = (i*fact[i-1])%m;
    }
    ll ans = 0;
    for(i=0; i<n; i++)
    {
        ll pres = (((n-i)*(n-i))%m * (fact[i+1]*fact[n-i-1]%m))%m;
        ans = (ans+pres)%m;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int t = 1;
    while(t--) solve();
    return 0;
}
