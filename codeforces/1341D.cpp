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
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2003;//   0          1          2          3          4          5          6          7           8         9
string a[N], dig[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int dp[N][N],n,k;
int bit[N][10];
//bit[i][j] - Distance from a[i] to j
//dp[i][j] - if its possible to make number from suffix i...n with j bits turned on.

void ans(int i, int j)
{
    if(i==n+1)
    {
        cout << "\n";
        return;
    }
    REB(t,9,0)
    {
        if(bit[i][t]!=-1 && dp[i+1][j-bit[i][t]] && bit[i][t]<=j)
        {
            cout << t;
            ans(i+1, j-bit[i][t]);
            return;
        }
    }
}

int solve_case()
{
    int i,j,t,m;
    cin >> n >> k;
    RE(i,n) cin >> a[i];
    RE(i,n)
    {
        FOR(j,10)
        {
            FOR(k,8)
            {
                if(dig[j][k]=='0' && a[i][k]=='1')
                {
                    bit[i][j] = -1;
                    break;
                }
                if(dig[j][k]=='1' && a[i][k]=='0') bit[i][j]++;
            }
        }
    }
    dp[n+1][0] = 1;
    FO(i,n+1)
    {
        REP(j,0,k)
        {
            if(!dp[i][j]) continue;
            FOR(t,10)
            {
                if(bit[i-1][t]!=-1 && bit[i-1][t] + j <= k)
                    dp[i-1][j+bit[i-1][t]] = 1;
            }
        }
    }
    if(!dp[1][k]) return cout << "-1\n",0;
    ans(1,k);
    return 0;
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
