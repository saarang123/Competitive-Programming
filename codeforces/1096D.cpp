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

const int N = 1e5+5;
int a[N], dp[N][5] = {};
char an[] = {'1', 'h', 'a', 'r', 'd'};

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    string s;
    cin >> s;
    RE(i,n) cin >> a[i];
    RE(i,n) RE(j,4) dp[i][j] = 1e15;

    dp[1][1] = a[1]*(s[0]=='h');
    REP(i,2,n) dp[i][1] = dp[i-1][1] + a[i]*(s[i-1]=='h');
    REP(j,2,4)
    {
        dp[0][j] = 0;
        RE(i,n)
        {
            dp[i][j] = dp[i-1][j];
            if(s[i-1]==an[j])
            {
                dp[i][j] = min(dp[i][j] + a[i], dp[i-1][j-1]);
            }
        }
    }
    /*
    RE(j,4)
    {
        RE(i,n) cout << dp[i][j] << " "; cout << "\n";
    }
    */
    cout << dp[n][4] << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
