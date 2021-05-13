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

const int N = 1e5+2;
int dp[N][31], is[N][32], pref[N][32];
vector<pair<int, pii>> q;
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,m)
    {
        cin >> j >> k >> t;
        q.pb(mp(t,mp(j,k)));
        FOR(bit,30)
        {
            if(t & (1<<bit))
            {
                dp[j][bit] += 1;
                dp[k+1][bit] -= 1;
            }
        }
    }
    RE(i,n)
    {
        FOR(j,30)
        {
            dp[i][j] += dp[i-1][j];
            if(dp[i][j]) is[i][j]++;
        }
    }
    RE(i,n) FOR(j,30) pref[i][j] += pref[i-1][j] + is[i][j];

    FOR(i,m)
    {
        int qt = q[i].f, l = q[i].ss.f, r = q[i].ss.ss;
        FOR(j,30)
        {
            bool bit = (qt & (1<<j));
            if(bit && pref[r][j]-pref[l-1][j]!=(r-l+1))
            {
                cout << "NO\n";
                return;
            }
            if(!bit && pref[r][j]-pref[l-1][j]==(r-l+1))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    RE(i,n)
    {
        int num = 0;
        FOR(j,30)
        {
            num += is[i][j]*(1<<j);
        }
        cout << num << " ";
    }
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
