#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
//#define int long long
#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)
#define rip signed
#define kobe main()
#define bryant ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define setitr set <int, greater <int> > :: iterator
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 3e5+3;
int a[N], b[N], ans=0, dp[N], c[N],n;
vi g[N];

void dfs(int v, int p)
{
    if(c[v]==1) a[v] = 1;
    if(c[v]==2) b[v] = 1;
    FOR(i,g[v].size())
    {
        int u = g[v][i];
        if(u==p) continue;
        dfs(u,v);
        a[v] += a[u];
        b[v] += b[u];
    }
}

bool check(int v, int u, int p, int q)
{
    if((v && u) || (p && q)) return 0;
    return 1;
}

void reroot(int v, int p)
{
    //cout << v << ":\n";
    //RE(i,n) cout << a[i] << " "; cout << "\n";
    //RE(i,n) cout << b[i] << " "; cout << "\n";
    FOR(i,g[v].size())
    {
        int u = g[v][i];
        if(u==p) continue;
        a[v] -= a[u];
        b[v] -= b[u];
        if(check(a[v],b[v],a[u],b[u])) ans++;
        a[u] += a[v];
        b[u] += b[v];
        reroot(u,v);
        a[u] -= a[v];
        b[u] -= b[v];
        a[v] += a[u];
        b[v] += b[u];
    }
}

void pls_give_AC()
{
    int i,j,t,k,m;
    cin >> n;
    RE(i,n) cin >> c[i];
    RE(i,n-1)
    {
        cin >> j >> k;
        g[k].pb(j);
        g[j].pb(k);
    }
    dfs(1,-1);
    reroot(1,-1);
    cout << ans << "\n";
}

rip kobe
{
    bryant;
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        pls_give_AC();
    }
    return 0;
}
