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

const int N = 1e5+4;
int a[N],s[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("hayfeast.in", "r", stdin);
    //freopen("hayfeast.out", "w", stdout);
    ll n,i,j,t,k,m,sum=0;
    cin >> n >> m;
    RE(i,n)
    {
        cin >> a[i] >> s[i];
    }

    multiset<ll> se;
    int l = 1;
    ll ans = 1e15;
    RE(i,n)
    {
        se.insert(s[i]);
        sum+=a[i];
        if(sum-a[l]>=m)
        {
            sum-=a[i];
            se.erase(s[l]);
            l++;
        }
        if(sum>=m) ans = min(ans, *se.rbegin());
    }
    cout << ans << "\n";
    return 0;
}
