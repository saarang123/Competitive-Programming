#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
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

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

//-------------------------------------Template Ends------------------------------------------------//

const int N = 1e5+5;
int dp[3][N] = {1}, a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,n) cin >> a[i];
    dp[1][n] = 1;
    dp[2][n] = 1;
    REB(i,n-1,1)
    {
        dp[1][i] = 1, dp[2][i] = 1;
        if(a[i]<=a[i+1])
        {
            dp[1][i] = dp[1][i+1]+1;
        }
        if(a[i]>=a[i+1])
        {
            dp[2][i] = dp[2][i+1]+1;
        }
    }
    //RE(i,n) cout << dp[1][i] << " "; cout << "\n";
    //RE(i,n) cout << dp[2][i] << " "; cout << "\n";

    while(m--)
    {
        cin >> j >> k;
        if(k-j<=1)
        {
            cout << "Yes\n";
            continue;
        }
        if(j + dp[1][j] - 1 + dp[2][j+dp[1][j]-1] - 1 >= k)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
    return 0;
}
