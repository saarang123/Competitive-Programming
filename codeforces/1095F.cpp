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

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2e5+2;
vector<pair<int, pii>> ed;
pii a[N];
int par[N], len[N];

void init(int n)
{
    RE(i,n) par[i] = i, len[i] = 1;
}

int fin(int n)
{
    if(par[n]==n) return n;
    return par[n] = fin(par[n]);
}

void join(int a, int b)
{
    a = fin(a); b = fin(b);
    if(a==b) return;
    if(len[a]<len[b]) swap(a,b);
    len[a] += len[b];
    par[b] = a;
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    init(n);
    RE(i,n)
    {
        cin >> a[i].f;
        a[i].ss = i;
    }
    sort(a+1,a+n+1);
    RE(i,m)
    {
        int v,u,w;
        cin >> v >> u >> w;
        ed.pb(mp(w, mp(v,u)));
    }
    REP(i,2,n)
    {
        ed.pb(mp(a[1].f+a[i].f, mp(a[1].ss, a[i].ss)));
    }
    sort(all(ed));
    int ans = 0;
    for(auto p: ed)
    {
        int v = p.ss.f, u = p.ss.ss, w = p.f;
        if(fin(v)==fin(u)) continue;
        ans += w;
        join(v,u);
    }
    cout << ans << "\n";
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
