#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back

#define all(v) v.begin(),v.end()
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 1e5+5;
const int T = 24;
ll t = 20, par[N][T]={-1}, dt[N];
ll ds[N], d[21][N];
vector<pair<ll, pii> > edges;
vpii bad;
vi graph[N],gr[N];
map<pii, ll> wt;

void setup(ll n)
{
    REP(i,0,n)
    {
        dt[i] = i;
    }
}

ll parent(ll v)
{
    if(dt[v]==v)
    {
        return v;
    }
    return dt[v]=parent(dt[v]);
}

void join(ll a, ll b)
{
    a = parent(a);
    b = parent(b);
    if(a!=b)
    {
        dt[b] = a;
    }
}

void kruskals()
{
    sort(all(edges));
    REP(i,0, edges.size()-1)
    {
        ll v = edges[i].ss.f, u = edges[i].ss.ss;
        ll w = edges[i].f;
        if(parent(v)!=parent(u))
        {
            join(v,u);
            wt[mp(u,v)] = w;
            wt[mp(v,u)] = w;
            graph[v].pb(u);
            graph[u].pb(v);
        }
        else
        {
            bad.pb(mp(min(v,u), max(v,u)));
        }
    }
}

void dfs(ll v, ll p, ll d, ll w)
{
    dt[v] = d;
    ds[v] = w + wt[mp(p,v)];
    par[v][0] = max(0LL,p);
    RE(i,t)
    {
        ll pa = par[v][i-1];
        if(pa!=-1)
        {
            par[v][i] = par[pa][i-1];
        }
    }
    REP(i,0,graph[v].size()-1)
    {
        ll u = graph[v][i];
        if(u==p) continue;
        dfs(u,v,d+1, ds[v]);
    }
}

ll kth_parent(ll v, ll k)
{
    REP(i,0,t)
    {
        if((1<<i) & k)
        {
            v = par[v][i];
        }
    }
    return v;
}

ll lca(ll a, ll b)
{
    if(dt[a]>dt[b])
    {
        a = kth_parent(a, dt[a]-dt[b]);
    }
    else if(dt[b]>dt[a])
    {
        b = kth_parent(b, dt[b]-dt[a]);
    }
    if(a==b) return a;
    REB(i,t,0)
    {
        if(par[a][i]!=par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

ll dist(ll a, ll b)
{
    return ds[a]+ds[b]-2*ds[lca(a,b)];
}

void dij(ll v,ll d[], ll n)
{
    set<pll> q;
    RE(i,n) d[i-1] = LLONG_MAX;
    d[v] = 0;
    q.insert(mp(d[v],v));
    while(!q.empty())
    {
        ll v = (*q.begin()).ss;
        q.erase(q.begin());
        REP(i,0,gr[v].size()-1)
        {
            ll u = gr[v][i]; ll w = wt[mp(v,u)];
            if(d[u]>d[v]+w)
            {
                q.erase(mp(d[u],u));
                d[u] = d[v] + w;
                q.insert(mp(d[u],u));
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j,q,m; ll k;
    cin >> n >> m;
    setup(n);
    while(m--)
    {
        cin >> i >> j >> k;
        i--,j--;
        gr[i].pb(j);
        gr[j].pb(i);
        wt[mp(j,i)] = k;
        wt[mp(i,j)] = k;
        edges.pb(mp(k,mp(i,j)));
    }
    kruskals();
    dfs(0,-1,0,0);
    //RE(i,n) cout << ds[i-1] << " "; cout << "\n";
    /*
    RE(i,n)
    {
        cout << i-1 << ": ";
        REP(j,0,graph[i-1].size()-1)
        {
            cout << graph[i-1][j] << " ";
        }
        cout << "\n";
    }
    */
    ll pos = 0;
    REP(i,0,bad.size()-1)
    {
        dij(bad[i].f, d[pos++],n);
    }

    cin >> q;
    while(q--)
    {
        cin >> i >> j;
        i--,j--;
        ll ans = dist(i,j);
        REP(u,0,bad.size()-1)
        {
            ans = min(ans, d[u][i] + d[u][j]);
        }
        cout << ans << "\n";
    }
    return 0;
}
