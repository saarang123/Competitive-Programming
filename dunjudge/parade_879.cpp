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

const int N = 5e5+1;
vpii graph[N];
int p[N],pp[N], dt[N];
ll dp[N];

int dfs(int v, int pa, int d, int w)
{
    pp[v] = p[v];
    dt[v] = d + w;
    REP(i,0,graph[v].size()-1)
    {
        int u = graph[v][i].f, w = graph[v][i].ss;
        if(u==pa) continue;
        pp[v] += dfs(u,v,dt[v],w);
    }
    return pp[v];
}

void reroot(int v, int pa, int pd)
{
    REP(i,0,graph[v].size()-1)
    {
        int u = graph[v][i].f, w = graph[v][i].ss;
        if(u==pa) continue;
        pp[v] -= pp[u];
        dp[u] = dp[v] - (pp[u]*w) + (pp[v]*w);
        pp[u] += pp[v];
        reroot(u,v,dp[u]);
        pp[u] -= pp[v];
        pp[v] += pp[u];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n) cin >> p[i-1];
    RE(i,n-1)
    {
        cin >> j >> k >> t;
        graph[j].pb(mp(k,t));
        graph[k].pb(mp(j,t));
    }
    dfs(0,-1,0,0);
    dp[0] = 0;
    REP(i,0,n-1)
    {
        dp[0] += p[i]*dt[i];
    }
    reroot(0,-1,dp[0]);
    REP(i,0,n-1) cout << dp[i] << " "; cout << "\n";
    return 0;
}
