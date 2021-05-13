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
vi graph[N];
int deg[N], dt[N];

void dfs(int v, int p, int d)
{
    dt[v] = d;
    REP(i,0,graph[v].size()-1)
    {
        int u = graph[v][i];
        if(u==p) continue;
        dfs(u,v,d+1);
    }
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n-1)
    {
        cin >> j >> k;
        deg[j]++, deg[k]++;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    int mi,ma;
    RE(i,n)
    {
        if(deg[i]==1) continue;
        dfs(i,-1,0);
        break;
    }
    bool odd=0, even=0;
    set<int> par;
    int leaf_cnt = 0;
    RE(i,n)
    {
        if(deg[i]==1)
        {
            if(dt[i]&1) odd = 1;
            else even = 1;
            leaf_cnt++;
            par.insert(graph[i][0]);
        }
    }
    if(odd && even) mi = 3;
    else mi = 1;
    //if leaves hv same parent, their weights hv to be same for xor as 0.
    //Rest all can be accomodated anyhow.
    ma = n-1-(leaf_cnt-par.size());
    cout << mi << " " << ma << "\n";
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
