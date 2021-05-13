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

int K1(int n)
{
    if(n%3==0) return 1;
    return 0;
}

int K2(int n)
{
    int dp[n+2];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    REP(i,4,n)
    {
        dp[i] = (dp[i-2] + dp[i-3])%mod;
    }
    return dp[n];
}

int K3(int n)
{
    int dp[n+3][5] = {0};
    //dp[i][0] - i rows filled with 0 extra.
    //dp[i][1] - i rows filled with one extra of size 1.
    //dp[i][2] - i rows filled with one extra of size 2.
    //dp[i][3] - i rows filled with 2 extras of size 1.
    //dp[i][4] - i rows filled with 2 extras of size 2.
    dp[0][0] = 1;
    dp[0][4] = 1;
    dp[1][0] = 1;
    dp[1][4] = 1;
    dp[2][0] = 1;
    dp[2][1] = 1;
    dp[2][4] = 1;
    REP(i,3,n)
    {
        dp[i][0] = (dp[i-1][0] + dp[i-3][0] + dp[i-3][3] + dp[i-2][2])%mod;
        dp[i][1] = dp[i-2][4];
        dp[i][2] = dp[i-1][3];
        dp[i][3] = (dp[i-1][1] + dp[i-2][2])%mod;
        dp[i][4] = (dp[i][0] + dp[i-1][1])%mod;
    }
    /*
    RE(j,5)
    {
        RE(i,n) cout << dp[i][j-1] << " "; cout << "\n";
    }
    */
    return dp[n][0];
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> k >> n;
    if(k==1) cout << K1(n) << "\n";
    else if(k==2) cout << K2(n) << "\n";
    else cout << K3(n) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
