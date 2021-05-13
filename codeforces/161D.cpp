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

const int N = 5e4+4;
vi graph[N];
int dist[N][503],k, ans=0;

void dfs(int v, int p)
{
    dist[v][0] = 1;
    for(int i=0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p) continue;
        dfs(u,v);
        RE(j,k)
        {
            dist[v][j] += dist[u][j-1];
        }
    }
    //Length k path from sm point in subtree to v.
    ans += dist[v][k];
    int pres = 0;
    //Length k path of 2 points lying in subtree of v.
    for(int i=0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p) continue;
        RE(j,k-1)
        {
            pres += (dist[u][j-1]*(dist[v][k-j]-dist[u][k-j-1]));
            //Length j-1 path in subtree of u + 1 (u to v) + length k-j path in subtree of v.
        }
    }
    ans += pres/2;
}

void solve_case()
{
    int n,i,j,t,m;
    cin >> n >> k;
    RE(i,n-1)
    {
        cin >> j >> m;
        graph[j].pb(m);
        graph[m].pb(j);
    }
    dfs(1,-1);
    cout << ans << "\n";
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
