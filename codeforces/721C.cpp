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
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e10;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 5002;
int dp[N][N] = {0},n;
vpii g[N];
vi sol;


int dfs(int v, int j)
{
    if(v==n && j==0) return 0;
    else if(v==n) return INF;
    if(j<=0) return INF;
    if(dp[v][j]!=-1) return dp[v][j];
    int mx = INF;
    for(int i=0; i<g[v].size(); i++)
    {
        int u = g[v][i].f, w = g[v][i].ss;
        mx = min(mx, dfs(u,j-1)+w);
    }
    dp[v][j] = mx;
    return dp[v][j];
}

void ans(int v, int j)
{
    if(v==n) return;
    for(int i=0; i<g[v].size(); i++)
    {
        int u = g[v][i].f, w = g[v][i].ss;
        if(dp[v][j] == dfs(u,j-1)+w)
        {
            sol.pb(u);
            ans(u,j-1);
            return;
        }
    }
}


void solve_case()
{
    int i,j,t,k,m,w;
    cin >> n >> m >> t;

    RE(i,m)
    {
        cin >> j >> k >> w;
        g[j].pb(mp(k,w));
    }
    RE(i,n) RE(j,n) dp[i][j] = -1;
    //RE(i,n) RE(j,n) dfs(i,j);
    /*
    RE(i,n)
    {
        RE(j,n) cout << dp[i][j] << " "; cout << "\n";
    }
    */
    REB(i,n,2)
    {
        if(dfs(1,i-1)<=t)
        {
            sol.clear();
            sol.pb(1);
            ans(1,i-1);
            cout << sol.size() << "\n";
            for(j=0; j<sol.size(); j++) cout << sol[j] << " "; cout << "\n";
            break;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
