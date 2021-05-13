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

const int N = 1e3+2;
vi g[N];
int dt[N],deg[N];

void dfs(int v, int p, int d)
{
    dt[v] = d;
    for(int u: g[v])
    {
        if(u==p) continue;
        dfs(u,v,d+1);
    }
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,n)
    {
        g[i].clear();
        deg[i] = 0;
        dt[i] = 0;
    }
    RE(i,n-1)
    {
        cin >> j >> k;
        g[j].pb(k);
        g[k].pb(j);
        deg[j]++;
        deg[k]++;
    }
    if(deg[m]==1)
    {
        cout << "Ayush\n";
        return;
    }
    dfs(m,-1,0);
    sort(dt+1, dt+n+1, greater<int>());
    //RE(i,n) cout << dt[i] << " "; cout << '\n';
    int turn = -1;
    for(i=1; i<=n; i++)
    {
        turn++;
        if(dt[i]>1) continue;
        if(deg[m]==1) break;
        deg[m]--;
    }
    if(turn%2==0) cout << "Ayush\n";
    else cout << "Ashish\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}