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

const int N = 42;
int dp[N][N][N][N], pref[N][N], rect[N][N][N][N], a[N][N];


int sum(int a, int b, int c, int d)
{
    return pref[c][d] - pref[a-1][b-1] - pref[a-1][d] - pref[c][b-1];
}

void solve_case()
{
    int n,i,j,t,k,l,m;
    cin >> n >> m >> t;
    RE(i,n) RE(j,m)
    {
        char c;
        cin >> c;
        if(c=='1') a[i][j] = 1;
        else a[i][j] = 0;
    }
    RE(i,n)
    {
        RE(j,m)
        {
            pref[i][j] = a[i][j] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    RE(i,n)
    {
        RE(j,m)
        {
            REP(k,i,n)
            {
                REP(l,j,m)
                {
                    int st = sum(i,j,k,l);
                    if(st==0) rect[i][j][k][l]++;
                }
            }
        }
    }
    RE(i,n)
    {
        RE(j,m)
        {
            REB(k,)
            {
                RE(l,m)
                {
                    dp[i+1][j+1][k+1][l+1] = dp[i+1][j+1][k+1][l] + dp[i][j+1][k+1][l+1] + dp[i+1][j][k+1][l+1] + dp[i+1][j+1][k][l+1]
                                    - dp[i+1][j+1][k][l] - dp[i][j+1][k+1][l] - dp[i][j][k+1][l+1] - dp[i+1][j][k][l+1]
                                    + dp[i+1][j][k][l] + dp[i][j+1][k][l] + dp[i][j][k+1][l] + dp[i][j][k][l+1]
                                    - dp[i][j][k][l] + rect[i][j][k][l];
                }
            }
        }
    }
    while(t--)
    {
        cin >> i >> j >> k >> l;
        cout << dp[i][j][k][l] << "\n";
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
