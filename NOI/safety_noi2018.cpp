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

const int N = 7e3+2;
int dp[N][N], a[N], t[4*N];
//dp[i][j] - min moves for pref 1....i as safe with a[i] as j.

void build(int b[], int v, int tl, int tr)
{
    if(tl==tr)
        t[v] = b[tl];
    else
    {
        int tm = (tl+tr) >> 1;
        build(b, 2*v, tl, tm); build(b, 2*v+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 1e18;
    if(tl>=l && tr<=r) return t[v];
    int tm = (tl+tr) >> 1;
    return min(query(2*v, tl, tm, l, min(r,tm)),
               query(2*v+1, tm+1, tr, max(l,tm+1), r) );
}

void solve_case()
{
    int n,i,j,k,m;
    cin >> n >> m;
    RE(i,n) cin >> a[i];
    k = 5000;
    RE(i,k) dp[1][i] = abs(a[1]-i);
    build(dp[1], 1, 1, k);
    REP(i,2,n)
    {
        RE(j,k)
        {
            dp[i][j] = abs(a[i]-j) + query(1,1,k,max(0ll,j-m), min(k,j+m));
        }
        build(dp[i], 1, 1, k);
    }
    int ans = 2e18;
    RE(i,k) ans = min(ans, dp[n][i]);
    cout << ans << "\n";
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
