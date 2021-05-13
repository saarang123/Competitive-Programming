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
#define RE(i,n) for(int i=0; i<n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 24;
ll dp[(1<<N)][2], pt[1<<N];
pii a[N], x;

ll dist(pii a, pii b)
{
    return (abs(a.f-b.f)*abs(a.f-b.f) + abs(a.ss-b.ss)*abs(a.ss-b.ss));
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> x.f >> x.ss >> n;
    RE(i,n) cin >> a[i].f >> a[i].ss;
    dp[0][0] = 0;
    pt[0] = 0;
    dp[0][1] = INF;
    for(int mask=1; mask<(1<<n); mask++)
    {
        dp[mask][0] = dp[mask][1] = INF;
        RE(i,n)
        {
            if(!(mask & (1<<i))) continue;
            if(dp[mask][0] >= (dp[mask ^ (1<<i)][1] + dist(a[i], a[pt[mask ^ (1<<i)]]) + dist(a[i], x)))
            {
                dp[mask][0] = (dp[mask ^ (1<<i)][1] + dist(a[i], a[pt[mask ^ (1<<i)]]) + dist(a[i], x));
            }
            if(dp[mask][0] >= (dp[mask ^ (1<<i)][0] + dist(x, a[i])*2))
            {
                dp[mask][0] = (dp[mask ^ (1<<i)][0] + 2*dist(x, a[i]));
            }
            if(dp[mask][1] >= (dp[mask ^ (1<<i)][0] + dist(x, a[i])))
            {
                dp[mask][1] = (dp[mask ^ (1<<i)][0] + dist(x, a[i]));
                pt[mask] = i;
            }
        }
    }
    cout << dp[(1<<n)-1][0] << "\n";
    vi ans;
    int mask = (1<<n)-1, ind = 0;
    while(mask!=0)
    {
        RE(i,n)
        {
            if(!(mask & (1<<i))) continue;
            if(ind==1)
            {
                if(dp[mask][1] == (dp[mask ^ (1<<i)][0] + dist(x, a[i])))
                {
                    ans.pb(i+1);
                    mask = mask ^ (1<<i);
                    ind = 0;
                    break;
                }
                continue;
            }
            if(dp[mask][0] == (dp[mask ^ (1<<i)][0] + dist(x, a[i])*2))
            {
                ans.pb(0);
                ans.pb(i+1);
                mask = mask ^ (1<<i);
                ind = 0;
                break;
            }
            if(dp[mask][0] == (dp[mask ^ (1<<i)][1] + dist(a[i], a[pt[mask ^ (1<<i)]]) + dist(a[i], x)))
            {
                ans.pb(0);
                ans.pb(i+1);
                mask = mask ^ (1<<i);
                ind = 1;
                break;
            }
        }
    }
    ans.pb(0);
    print(ans);
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
