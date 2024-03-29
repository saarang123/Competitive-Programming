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

const int N = 1e5+2;
int dt[N], wt;
vpii g[N];
void solve_case()
{
    // :pray: :fishy: :orz:
    int n,i,j,t,k,m,s;
    cin >> n >> m >> s;
    RE(_,m)
    {
        cin >> j >> k >> i;
        g[j].pb(mp(k,i));
        g[k].pb(mp(j,i));
    }
    cin >> wt;
    RE(i,n) dt[i] = 2e9;
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push(mp(0,s));
    dt[s] = 0;
    while(!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        if(dt[e.ss]!=e.f) continue;
        int v = e.ss;
        for(auto p: g[v])
        {
            int u = p.f, w = p.ss;
            if(dt[u] > dt[v] + w)
            {
                dt[u] = dt[v] + w;
                pq.push(mp(dt[u], u));
            }
        }
    }
    int ans = 0;
    RE(i,n) if(dt[i]==wt) ans++;
    RE(i,n)
    {
        if(dt[i]>=wt) continue;
        for(auto p: g[i])
        {
            int u = p.f, w = p.ss;
            int reqd = wt-dt[i];
            if(reqd >= w) continue;
            if(wt < dt[u] + w - reqd) ans++;
            else if(wt == dt[u] + w - reqd && i<u) ans++;
        }
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
