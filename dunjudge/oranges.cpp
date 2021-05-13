#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int N = 1e5+5;
const int T = 20;
int t = 16, par[N][T]={-1}, dt[N];
ll mx[N][T]={-1};
vector<pair<ll, pii> > edges;
vi graph[N];
map<pii, ll> wt;

void setup(int n)
{
    REP(i,0,n)
    {
        dt[i] = i;
    }
}

int parent(int v)
{
    if(dt[v]==v)
    {
        return v;
    }
    return dt[v]=parent(dt[v]);
}

void join(int a, int b)
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
        int v = edges[i].ss.f, u = edges[i].ss.ss;
        ll w = edges[i].f;
        if(parent(v)!=parent(u))
        {
            join(v,u);
            wt[mp(u,v)] = w;
            wt[mp(v,u)] = w;
            graph[v].pb(u);
            graph[u].pb(v);
        }
    }
}

void dfs(int v, int p, int d)
{
    dt[v] = d;
    par[v][0] = p;
    mx[v][0] = wt[mp(p,v)];
    RE(i,t)
    {
        int pa = par[v][i-1];
        if(pa!=-1)
        {
            par[v][i] = par[pa][i-1];
            mx[v][i] = max(mx[pa][i-1], mx[v][i-1]);
        }
    }
    REP(i,0,graph[v].size()-1)
    {
        ll u = graph[v][i];
        if(u==p) continue;
        dfs(u,v,d+1);
    }
}

pll kth_parent(int v, int k)
{
    ll ret = 0;
    REP(i,0,t)
    {
        if((1<<i) & k)
        {
            ret = max(ret, mx[v][i]);
            v = par[v][i];
        }
    }
    return mp(v,ret);
}

ll lca(int a, int b)
{
    ll ans=0;
    pll p;
    if(dt[a]>dt[b])
    {
        p = kth_parent(a, dt[a]-dt[b]);
        a = p.f;
        ans = p.ss;
    }
    else if(dt[b]>dt[a])
    {
        p = kth_parent(b, dt[b]-dt[a]);
        b = p.f;
        ans = p.ss;
    }
    if(a==b) return ans;
    REB(i,t,0)
    {
        if(par[a][i]!=par[b][i])
        {
            ans = max(max(mx[a][i], mx[b][i]), ans);
            a = par[a][i];
            b = par[b][i];
        }
    }
    ans = max(ans, max(mx[a][0], mx[b][0]));
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,q,m; ll k;
    cin >> n >> m >> q;
    setup(n);
    while(m--)
    {
        cin >> i >> j >> k;
        edges.pb(mp(k,mp(i,j)));
    }
    kruskals();
    dfs(0,-1,0);
    while(q--)
    {
        cin >> i >> j;
        cout << (ll) lca(i,j) << "\n";
    }
    return 0;
}
