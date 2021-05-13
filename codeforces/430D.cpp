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
int a[N][N], dp11[N][N]={0}, dp1M[N][N]={0}, dpNM[N][N]={0}, dpN1[N][N]={0};

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,n)
    {
        RE(j,m)
        {
            cin >> a[i][j];
        }
    }
    REP(i,0,n)
    {
        REP(j,0,m) {
            dp11[i][j]=0;
            dpN1[i][j]=0;
            dpNM[i][j]=0;
            dp1M[i][j]=0;
        }
    }

    RE(i,n)
    {
        RE(j,m)
            dp11[i][j] = a[i][j] + max(dp11[i-1][j],dp11[i][j-1]);
            //From (1,1) to (i,j)
    }
    RE(i,n)
        FO(j,m)
            dp1M[i][j] = a[i][j] + max(dp1M[i-1][j], dp1M[i][j+1]);
            //From (1,m) to (i,j)

    FO(i,n)
    {
        FO(j,m)
            dpNM[i][j] = a[i][j] + max(dpNM[i+1][j], dpNM[i][j+1]);
            //From (n,m) to (i,j)
    }
    FO(i,n)
    {
        RE(j,m)
            dpN1[i][j] = a[i][j] + max(dpN1[i+1][j], dpN1[i][j-1]);
            //From (n,1) to (i,j)
    }

    int ans = -1;
    REP(i,2,n-1)
    {
        REP(j,2,m-1)
        {
            ans = max(ans, dp11[i-1][j] + dpN1[i][j-1] + dpNM[i+1][j] + dp1M[i][j+1]);
            ans = max(ans, dp11[i][j-1] + dpN1[i+1][j] + dpNM[i][j+1] + dp1M[i-1][j]);
        }
    }
    cout << ans << "\n";
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
