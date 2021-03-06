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
int sz[N], cnt;
bool cent[N];
int ans[N];
vi graph[N];

void dfssz(int v, int p)
{
    sz[v] = 1;
    for(int i=0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p || cent[v]) continue;
        dfssz(u,v);
        sz[v] += sz[u];
    }
}

int fcent(int v, int p)
{
    for(int i=0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p || cent[u]) continue;
        if(sz[u] > cnt/2)
            return fcent(u, v);
    }
    return v;
}

void decompose(int v, int p, int lvl)
{
    dfssz(v,p);
    cnt = sz[v];
    int centroid = fcent(v,p);
    cent[centroid] = true;
    ans[centroid] = lvl;
    for(int i=0; i<graph[centroid].size(); i++)
    {
        int u = graph[centroid][i];
        if(u==p || cent[u]) continue;
        decompose(u, centroid, lvl+1);
    }
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    RE(i,n) cent[i] = 0;
    decompose(1,-1,0);
    RE(i,n) cout << (char)('A'+ans[i]) << " "; cout << "\n";
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
