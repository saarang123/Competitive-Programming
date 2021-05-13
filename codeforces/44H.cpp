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

int dp[53][12] = {0};
//dp[i][j] - No. of ways for elements from ith such that prev element is j
void solve_case()
{
    int n,i,j,t,k,m;
    string s;
    cin >> s;
    n = s.size();
    if(n==1)
    {
        cout << 9 << "\n";
        return;
    }
    REP(i,0,9) dp[n][i] = 1 + ((s[n-1]-'0')+i)%2;
    REB(i,n-1,1)
    {
        REP(j,0,9)
        {
            int ind = ((s[i-1]-'0') + j);
            dp[i][j] = dp[i+1][ind/2];
            if(ind%2)
            {
                dp[i][j] += dp[i+1][ind/2+1];
            }
        }
    }

    //RE(i,n){  REP(j,0,9) cout << dp[i][j] << " "; cout << "\n"; }
    int ans = 0;
    REP(i,0,9) ans += dp[2][i];

    bool pos = 1;
    RE(i,n-1)
    {
        int ind = (s[i]-'0') + (s[i-1]-'0');
        //cout << ind << "\n";
        if(ind/2 != (s[i]-'0') && (ind/2 + (ind%2)) != (s[i]-'0'))
        {
            pos = 0;
            break;
        }
    }
    cout << ans-pos << "\n";
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
