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
const int INF = 1e18;
const int LGN = 30;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 303;
const int M = 10;
int n, dp[N][1<<M], sz, a[N], bits[N], c[N];

vi prime(int n)
{
    vi tmp;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i) continue;
        while(n%i==0) n/=i;
        tmp.pb(i);
    }
    if(n>1) tmp.pb(n);
    return tmp;
}

int fn(int i, int mask)
{
    //cout << i << " " <<  mask << "\n";
    if(i==n+1)
    {
        if(mask==(1<<sz)-1) return 0;
        return INF;
    }
    if(dp[i][mask]!=-1) return dp[i][mask];
    dp[i][mask] = INF;
    dp[i][mask] = min(dp[i][mask], fn(i+1, mask));
    dp[i][mask] = min(dp[i][mask], fn(i+1, mask | bits[i]) + c[i]);
    return dp[i][mask];
}

void solve_case()
{
    int i,j,t,k,m;
    cin >> n;
    RE(i,n) cin >> a[i];
    RE(i,n) cin >> c[i];
    int ans = INF;
    RE(i,n)
    {
        vi pf = prime(a[i]);   //prime factors
        sz = pf.size();
        //print(pf);
        RE(j,n)
        {
            bits[j] = 0;
            FOR(k,sz)
            {
                if(a[j]%pf[k]!=0) bits[j] |= (1<<k);    //seeing divisors for others
            }
        }
        memset(dp, 0xff, sizeof(dp));
        //cout << i << ": bruh\n";
        ans = min(ans, c[i] + fn(1,0));   //one fixed and finding max we can choose so none intersect in all
    }
    if(ans>=INF) cout << -1 << "\n";
    else cout << ans << "\n";
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
