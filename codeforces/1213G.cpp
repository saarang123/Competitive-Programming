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

const int N = 2e5+2;
int par[N], len[N], ans[N], tot=0;

void init(int n)
{
    RE(i,n) par[i] = i, len[i] = 1;
}

int fin(int i)
{
    if(par[i]==i) return i;
    return par[i] = fin(par[i]);
}

int cnt(int v)
{
    return v * 1ll * (v-1) / 2;
}

void join(int v, int u)
{
    v = fin(v), u = fin(u);
    if(len[v]>len[u]) swap(u,v);
    tot -= cnt(len[v]);
    tot -= cnt(len[u]);

    len[u] += len[v];
    tot += cnt(len[u]);

    par[v] = u;
}

void solve_case()
{
    int n,i,j,k,m;
    cin >> n >> m;
    init(n);
    vector<pair<int, pair<int, int>>> edges;
    RE(i,n-1)
    {
        int v,u,w;
        cin >> v >> u >> w;
        edges.pb(mp(w,mp(v,u)));
    }
    sort(all(edges));
    vector<pair<int,int>> q;
    RE(i,m)
    {
        cin >> j;
        q.pb(mp(j,i));
    }
    sort(all(q));
    j = 0;
    FOR(i,m)
    {
        while(j<n-1 && edges[j].f<=q[i].f)
        {
            int v = edges[j].ss.f;
            int u = edges[j].ss.ss;
            join(v,u);
            j++;
        }
        //cout << tot << "\n";
        ans[q[i].ss] = tot;
    }
    RE(i,m) cout << ans[i] << " \n"[i==n];
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
