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
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 1e5+5;
vpii graph[N];
int sz[N], ds[N], gb[N], a[N];

int dfs(int v, int p, int d)
{
    sz[v] = 1;
    ds[v] = d;
    if(ds[v]>a[v]) gb[v] = 0;
    else gb[v] = 1;
    REP(i,0,graph[v].size()-1)
    {
        int u = graph[v][i].f, w = graph[v][i].ss;
        if(u==p) continue;
        sz[v] += dfs(u,v,max(0LL,d+w));
    }
    return sz[v];
}

int leaf(int v, int p)
{
    if(!gb[v]) return sz[v];
    int ans = 0;
    REP(i,0,graph[v].size()-1)
    {
        int u = graph[v][i].f;
        if(u==p) continue;
        ans += leaf(u,v);
    }
    return ans;
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n) cin >> a[i];
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[i+1].pb(mp(j,k));
        graph[j].pb(mp(i+1,k));
    }
    dfs(1,-1,0);
    //RE(i,n) cout << ds[i] << " "; cout << "\n";
    //RE(i,n) cout << gb[i] << " "; cout << "\n";
    cout << leaf(1,-1) << "\n";
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
