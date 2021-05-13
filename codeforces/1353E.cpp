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

#define setitr set <int, greater <int> > :: iterator
#define FO(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FOR(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/
const int N = 1e6+3;
int pref[N], a[N], dp[N][2];
//dp[i][j] - Min changes to make suffix i...n k-periodic such that a[i] = j (0 or 1).

int sum(int l, int r)
{
    return pref[r] - pref[l-1];
}

void solve_case()
{
    int n,i,j,k,m;
    cin >> n >> k;
    string s;
    cin >> s;
    FO(i,n) a[i+1] = s[i]-'0';
    pref[0] = 0;
    RE(i,n) pref[i] = pref[i-1] + a[i];
    dp[n][0] = 0, dp[n][1] = 0;
    REB(i,n-1,1)
    {
        if(a[i])
        {
            dp[i][0] = 1 + min(dp[i+1][1], dp[i+1][0]);
            if(i+k>n)
            {
                dp[i][1] = sum(i+1,n);
            }
            else
            {
                dp[i][1] = sum(i+1,i+k-1) + dp[i+k][1];
                dp[i][1] = min(dp[i][1], sum(i+1,n));
            }
        }
        else
        {
            dp[i][0] = min(dp[i+1][1], dp[i+1][0]);
            if(i+k>n)
            {
                dp[i][1] = 1 + sum(i+1,n);
            }
            else
            {
                dp[i][1] = 1 + sum(i+1,i+k-1) + dp[i+k][1];
                dp[i][1] = min(dp[i][1], 1 + sum(i+1,n));
            }
        }
    }
    cout << min(dp[1][1], dp[1][0]) << "\n";
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
