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

//-------------------------------------------------Template Ends------------------------------------------------------/

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5+2;
int n,k,m,vis[N];
vi cycle,g[N];
set<int> ind;

void dfs(int v)
{
    cycle.pb(v);
    vis[v] = 1;
    int add = 1;
    for(int u: g[v])
    {
        add = add & !ind.count(u);
    }
    if(add)
    {
        ind.insert(v);
        if(ind.size()==k)
        {
            cout << "1\n";
            for(int u: ind) cout << u << " "; cout << "\n";
            exit(0);
        }
    }
    for(int u: g[v])
    {
        if(cycle[0]==u && cycle.size()>=k && cycle.size()>2)
        {
            cout << 2 << "\n" << cycle.size() << "\n";
            for(int to: cycle) cout << to << " "; cout << "\n";
            exit(0);
        }
        if(!vis[u]) dfs(u);
    }
    cycle.pop_back();
}

void solve_case()
{
    int i,j,t;
    cin >> n >> m;
    k = 1;
    while(k*k<n) k++;
    while(m--)
    {
        cin >> i >> j;
        g[i].pb(j);
        g[j].pb(i);
    }
    while(1)
    {
        ind.clear();
        RE(i,n) vis[i] = 0;
        dfs(rng() % n);
    }
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
