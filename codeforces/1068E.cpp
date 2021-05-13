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

const int N = 1e5+2;
vi g[N], diam;   //graph, diameter
int p[N],n,k,cent;  //par, dist

void fail()
{
    cout << "No\n";
    exit(0);
}

pii dfs(int v, int par, int d)
{
    p[v] = par;
    pii ret = mp(d,v);
    for(int u: g[v])
    {
        if(u==par) continue;
        ret = max(ret, dfs(u, v, d+1));
    }
    return ret;
}


bool orz(int v, int par, int d)
{
    if(d==k)
    {
        if(g[v].size()!=1) return false;
        return true;
    }
    if(g[v].size()<3) return false;
    if(v!=cent && g[v].size()<4) return false;
    for(int u: g[v])
    {
        if(u==par) continue;
        if(!orz(u,v,d+1)) return false;
    }
    return true;
}

void solve_case()
{
    int i,j,t,m;
    cin >> n >> k;
    RE(i,n-1)
    {
        cin >> j >> t;
        g[t].pb(j);
        g[j].pb(t);
    }
    pii d1 = dfs(1,-1,0);
    pii d2 = dfs(d1.ss,-1,0);
    int v = d2.ss;
    while(v!=d1.ss)
    {
        diam.pb(v);
        v = p[v];
    }
    diam.pb(d1.ss);
    cent = -1;
    int sz = diam.size();
    if(sz!=2*k+1)
    {
        cout << "No\n";
        return;
    }
    FOR(i,sz)
    {
        if(i==k && sz-i-1==k)
        {
            cent = diam[i];
            break;
        }
    }
    //or(int u: diam) cout << u << " "; cout << "\n";
    //cout << cent << "\n";
    if(cent==-1) fail();
    if(g[cent].size()<3) fail();
    if(orz(cent,-1,0)) cout << "Yes\n";
    else cout << "No\n";

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
