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

const int N = 103;
int n,m, a[N][N];

int dist(int a, int b, int x, int y)
{
    return abs(a-x) + abs(b-y);
}

int calc1(int x, int y)
{
    int dp[n+2][m+2];
    dp[x][y] = 0;
    FO(i,x)
    {
        FO(j,y)
        {
            if(i==x && j==y) continue;
            else if(i==x)
            {
                dp[i][j] = 1e18;
                if(a[i][j] >= (a[x][y]-dist(i,j,x,y))) dp[i][j] = dp[i][j+1] + (a[i][j]-(a[x][y]-dist(i,j,x,y)));
            }
            else if(j==y)
            {
                dp[i][j] = 1e18;
                if(a[i][j] >= (a[x][y]-dist(i,j,x,y))) dp[i][j] = dp[i+1][j] + (a[i][j]-(a[x][y]-dist(i,j,x,y)));
            }
            else
            {
                dp[i][j] = 1e18;
                if(a[i][j] >= (a[x][y]-dist(i,j,x,y))) dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + (a[i][j]-(a[x][y]-dist(i,j,x,y)));
            }
        }
    }
    return dp[1][1];
}

int calc2(int x, int y)
{
    int dp[n+2][m+2];
    dp[x][y] = 0;
    REP(i,x,n)
    {
        REP(j,y,m)
        {
            if(i==x && j==y) continue;
            else if(i==x)
            {
                dp[i][j] = 1e18;
                if(a[i][j] >= (a[x][y]+dist(i,j,x,y))) dp[i][j] = dp[i][j-1] + (a[i][j]-(a[x][y]+dist(i,j,x,y)));
            }
            else if(j==y)
            {
                dp[i][j] = 1e18;
                if(a[i][j] >= (a[x][y]+dist(i,j,x,y))) dp[i][j] = dp[i-1][j] + (a[i][j]-(a[x][y]+dist(i,j,x,y)));
            }
            else
            {
                dp[i][j] = 1e18;
                if(a[i][j] >= (a[x][y]+dist(i,j,x,y))) dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (a[i][j]-(a[x][y]+dist(i,j,x,y)));
            }
        }
    }
    return dp[n][m];
}

void solve_case()
{
    int i,j,t,k;
    cin >> n >> m;
    RE(i,n) RE(j,m) cin >> a[i][j];
    int ans = 2e18;
    RE(i,n)
    {
        RE(j,m)
        {
            int pres = calc1(i,j) + calc2(i,j);   //fix 1 and find rest orz
            ans = min(ans,pres);
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
