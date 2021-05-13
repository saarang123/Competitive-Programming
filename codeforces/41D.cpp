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

#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 105;
int dp[N][N][12], up[N][N][12], a[N][N],t,n,m;
//d[i][j][k] - Sum on path from (i,j) to 1th row with sum%t = k.

void soln(int i, int j, int k)
{
    if(i==n)
    {
        cout << j << "\n";
        return;
    }
    if(up[i][j][k%(t)]==j+1)
    {
        soln(i+1,j+1,k-a[i][j]);
        cout << "L";
        return;
    }
    soln(i+1,j-1,k-a[i][j]);
    cout << "R";
}


void solve_case()
{
    int i,j,k;
    cin >> n >> m >> t;
    t++;
    RE(i,n)
    {
        RE(j,m)
        {
            char c;
            cin >> c;
            a[i][j] = c-'0';
            //Matrix is reversed cuz 1st row is actually nth and nth is actually first.
        }
    }
    REP(i,0,n) REP(j,0,m) REP(k,0,t) dp[i][j][k] = -1, up[i][j][k] = -1;
    RE(i,m)
    {
        dp[n][i][(a[n][i])%(t)] = a[n][i];
    }
    REB(i,n-1,1)
    {
        RE(j,m)
        {
            REP(k,0,t-1)
            {
                int v = (k + a[i][j])%(t);
                if(j>1)
                {
                    if(dp[i+1][j-1][k]>=0)
                    {
                        if(dp[i+1][j-1][k] + a[i][j] > dp[i][j][v])
                        {
                            dp[i][j][v] = dp[i+1][j-1][k] + a[i][j];
                            up[i][j][v] = j-1;
                        }
                    }
                }
                if(j<m)
                {
                    if(dp[i+1][j+1][k]>=0)
                    {
                        if(dp[i+1][j+1][k] + a[i][j] > dp[i][j][v])
                        {
                            dp[i][j][v] = dp[i+1][j+1][k] + a[i][j];
                            up[i][j][v] = j+1;
                        }
                    }
                }
            }
        }
    }
    int ind = 0;
    RE(i,m)
    {
        if(dp[1][i][0] > dp[1][ind][0])
        {
            ind = i;
        }
    }
    cout << dp[1][ind][0] << "\n";
    if(ind==0) return;
    soln(1,ind,dp[1][ind][0]);
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
