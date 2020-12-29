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
vpii g[N];
vector<pair<pii, pii>> edges;
int ans[N], par[N], len[N];
int sparse[N][19], mx[N][19], dt[N], lg=18;

void init(int n)
{
    RE(i,n) par[i] = i, len[i] = 1;
}

int fin(int v)
{
    if(par[v]==v) return v;
    return par[v] = fin(par[v]);
}

bool join(int a, int b)
{
    a = fin(a); b = fin(b);
    if(a==b) return false;
    if(len[a] < len[b]) swap(a,b);
    len[a] += len[b];
    par[b] = a;
    return true;
}


void kruskals()
{
    int cost = 0;
    vi mst;
    vector<pair<pii, pii>> ed = edges;
    sort(all(ed));
    for(auto p: ed)
    {
        int w = p.f.f, ind = p.f.ss, v = p.ss.f, u = p.ss.ss;
        if(join(v,u))
        {
            mst.pb(ind);
            g[v].pb(mp(u,w));
            g[u].pb(mp(v,w));
            cost += w;
        }
    }
    //print(mst);
    //cout << cost << "\n";
    for(int v: mst) ans[v] = cost;
}


void dfs(int v, int p, int d, int w)
{
    dt[v] = d;
    sparse[v][0] = p;
    mx[v][0] = w;
    RE(i,lg)
    {
        if(sparse[v][i-1]==-1) continue;
        sparse[v][i] = sparse[sparse[v][i-1]][i-1];
        mx[v][i] = max(mx[sparse[v][i-1]][i-1], mx[v][i-1]);
    }
    for(auto nxt: g[v]) if(nxt.f!=p)
    {
        int u = nxt.f, ws = nxt.ss;
        dfs(u, v, d+1, ws);
    }
}

pii kth_parent(int v, int k)
{
    ll wt = 0;
    REP(i,0,lg)
    {
        if(k & (1<<i))
        {
            wt = max(wt, mx[v][i]);
            v = sparse[v][i];
        }
    }
    return mp(v,wt);
}

ll lca(int a, int b)
{
    if(dt[a]<dt[b]) swap(a,b);
    int diff = dt[a]-dt[b];
    pii p = kth_parent(a, diff);
    //cout << p.f << " " << p.ss << "\n";
    a = p.f;
    int ans = p.ss;
    if(a==b) return ans;
    REB(i,lg,0)
    {
        if(sparse[a][i]!=sparse[b][i])
        {
            ans = max(ans, mx[a][i]);
            ans = max(ans, mx[b][i]);
            a = sparse[a][i];
            b = sparse[b][i];
        }
    }
    ans = max(ans, mx[a][0]);
    ans = max(ans, mx[b][0]);
    return ans;
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    init(n);
    RE(x,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.pb(mp(mp(w,x), mp(u,v)));
    }
    RE(i,m) ans[i] = -1;
    kruskals();
    dfs(1, 1, 0, 0);
    int cost = 0;
    RE(i,m) if(ans[i]!=-1) cost = ans[i];
    for(auto p: edges)
    {
        int w = p.f.f, ind = p.f.ss, v = p.ss.f, u = p.ss.ss;
        if(ans[ind]!=-1) continue;
        int lc = lca(v,u);
        ans[ind] = cost + w - lc;
        //cout << v << " " << u << " " << ind << " " << lc << " v u ind lcawt\n";
    }
    //RE(i,n) cout << dt[i] << " \n"[i==n];
    /*
    RE(i,n)
    {
        REP(j,0,lg) cout << sparse[i][j] << " "; cout << "\n";
    }
    RE(i,n)
    {
        REP(j,0,lg) cout << mx[i][j] << " "; cout << "\n";
    }
    */
    RE(i,m) cout << ans[i] << "\n";
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
