#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define int long long
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

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define trav(i,a) for(auto i: a)
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2e5+2;
int up[N][21], t, dt[N], ans[N], a[N];
vpii g[N];

void dfs(int v, int p, int w) {
    up[v][0] = p;
    dt[v] = w;
    RE(i,t) up[v][i] = up[up[v][i-1]][i-1];
    for(auto aa: g[v]) if(aa.f!=p)
    {
        dfs(aa.f, v, w+aa.ss);
    }
}

void fix(int v, int p)
{
    for(auto pr: g[v])
    {
        int u = pr.f;
        if(u==p) continue;
        fix(u,v);
        ans[v] += ans[u];
    }
}

void solve_case()
{
    // :pray: :fishy: :orz:
    int n,i,j,k,m;
    cin >> n;
    RE(i,n) cin >> a[i];
    REP(i,2,n)
    {
        cin >> j >> k;
        g[i].pb(mp(j,k));
        g[j].pb(mp(i,k));
    }
    t = 18;
    dfs(1,0,0);
    RE(i,n)
    {
        int v = i, u = i;
        REB(j,t,0)
        {
            if(v!=1 && dt[u] - dt[up[v][j]] <= a[u])
            {
                v = up[v][j];
            }
        }
        ans[up[v][0]]--;
        ans[up[u][0]]++;
    }
    fix(1,0);
    RE(i,n) cout << ans[i] << " \n"[i==n];
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
