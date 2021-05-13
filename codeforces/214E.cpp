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

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 303;
int a[N][N], dp[N][N][N], n;
//dp[i][j][diff] - one path on (i,j) and other on diff squares away i thonk.
void solve_case()
{
    int i,j,t,k,m;
    cin >> n;
    for(i=0; i<n; i++) for(j=0; j<n; j++) cin >> a[i][j];
    for(i=0; i<=n; i++) for(j=0; j<=n; j++) for(k=0; k<=n; k++) dp[i][j][k] = -1e8;

    auto check = [&](int x, int y)
    {
        return (x>=0 && x<n) && (y>=0 && y<n);
    };

    dp[0][0][0] = a[0][0];
    for(int dist=1; dist<2*n-1; dist++)
    {
        for(i=0; i<=dist; i++)
        {
            for(int diff=0; diff<N-2; diff++)
            {
                int x1 = i, y1 = dist-i;
                int x2 = i-diff, y2 = dist-i+diff;
                if(!check(x1,y1)) continue;
                if(!check(x2,y2)) continue;
                if(check(x1-1, y1))
                {
                    if(check(x2,y2-1) && diff) dp[x1][y1][diff] = max(dp[x1][y1][diff], dp[x1-1][y1][diff-1]);
                    if(check(x2-1, y2)) dp[x1][y1][diff] = max(dp[x1][y1][diff], dp[x1-1][y1][diff]);
                }
                if(check(x1,y1-1))
                {
                    if(check(x2,y2-1)) dp[x1][y1][diff] = max(dp[x1][y1][diff], dp[x1][y1-1][diff]);
                    if(check(x2-1,y2)) dp[x1][y1][diff] = max(dp[x1][y1][diff], dp[x1][y1-1][diff+1]);
                }

                if(diff)
                {
                    dp[x1][y1][diff] += a[x1][y1];
                    dp[x1][y1][diff] += a[x2][y2];
                }
                else
                {
                    dp[x1][y1][diff] += a[x1][y1];
                }
            }
        }
    }
    cout << dp[n-1][n-1][0] << "\n";
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
