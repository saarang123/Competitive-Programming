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
const int INF = 1e16;
const int LGN = 30;
const int N = 1003;

//-------------------------------------------------Template Ends------------------------------------------------------/

int a[N], dp[N], dp2[N];

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n) cin >> a[i];
    RE(i,n)
    {
        dp[i] = 1;   //Number of moves till it reaches back to itself
        dp2[i] = 0;
        REP(j,a[i],i-1)
        {
            dp[i] += dp[j]+1;   //When j goes and reaches back, it has to move to (j+1) on the even count time.
            dp[i] %= mod;
        }
        dp2[i] = (dp2[i-1] + dp[i] + 1)%mod;  //dp2[i] is number of moves to reach ith place.
    }
    //RE(i,n) cout << dp[i] << " "; cout << "\n";
    cout << dp2[n] << "\n";
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
