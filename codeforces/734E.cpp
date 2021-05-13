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

const int N = 2e5+3;
vi g[N];
int a[N], par[N];
vpii ed;

void init(int n)
{
    RE(i,n) par[i] = i;
}

int fin(int v)
{
    if(par[v]==v) return v;
    return par[v] = fin(par[v]);
}

void join(int a, int b)
{
    a = fin(a); b = fin(b);
    if(a==b) return;
    if(rng()%2) par[a] = b;
    else par[b] = a;
}

pii dfs(int v, int par, int d)
{
    pii ret = mp(d,v);
    for(int u: g[v])
    {
        if(u==par) continue;
        ret = max(ret, dfs(u, v, d+1));
    }
    return ret;
}

void solve_case()
{
    // :pray: :fishy: :orz:
    int n,i,j,t,k,m;
    cin >> n;
    init(n);
    RE(i,n) cin >> a[i];
    RE(_,n-1)
    {
        cin >> i >> j;
        if(a[i]==a[j]) join(i,j);
        ed.pb(mp(i,j));
    }
    for(pii p: ed)
    {
        i = fin(p.f); j = fin(p.ss);
        if(i==j) continue;
        g[i].pb(j);
        g[j].pb(i);
    }
    int root = -1;
    RE(i,n) if(fin(i)==i) root = i;
    pii d1 = dfs(root,-1,0);
    pii d2 = dfs(d1.ss,-1,0);
    cout << (d2.f+1)/2 << "\n";
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
