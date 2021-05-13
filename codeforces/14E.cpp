#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define int long long
#define ll long long
#define double long double
#define fs first
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
int dp[23][5][12][12][2]={-1},t,n;
//dp[i][h][j][k][l] - Answer from (1,smthing) to (i,h) with j ups n k downs with last one as up/down.
//l==1 - Last down, l==0 - last up

int f(int i, int up, int down, int h, int l)
{
    if(i==n)
    {
        if(up==t && down==t-1)
        {
            return dp[i][h][up][down][l] = 1;
        }
        return dp[i][h][up][down][l] = 0;
    }
    if(dp[i][h][up][down][l]!=-1) return dp[i][h][up][down][l];
    if(up+down > (2*t-1)) return 0;
    int &ret = dp[i][h][up][down][l];
    ret = 0;
    if(l==0) //Last was down.
    {
        RE(nh,4)
        {
            if(nh>h) ret += f(i+1,up,down,nh,l);
            if(nh<h) ret += f(i+1,up+1,down,nh,!l);
        }
    }
    else //Last was up
    {
        RE(nh,4)
        {
            if(nh>h) ret += f(i+1,up,down+1,nh,!l);
            if(nh<h) ret += f(i+1,up,down,nh,l);
        }
    }
    return dp[i][h][up][down][l] = ret;
}

void solve_case()
{
    int i,j,k,m;
    cin >> n >> t;
    if(2*t-1>=n-1)
    {
        cout << 0 << "\n";
        return;
    }
    REP(i,0,n)
    {
        REP(j,0,t) REP(k,0,t) RE(m,4) dp[i][m][j][k][0] = -1, dp[i][m][j][k][1] = -1;
    }
    int ans = 0;
    RE(i,4)
    {
        RE(j,i-1) ans += (f(2,0,0,i,0));
        //First dude(j) has to be < 2nd one(i) for it to go up(1st has to go up?).
    }
    cout << ans << "\n";
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
