#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 1005;
int a[12], b[12], c[12], d[12];
int dp[N][12] = {0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >>n >> m >> c[0] >> d[0];
    RE(i,m)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    RE(i,m) dp[0][i] = 0;
    RE(i,n)
    {
        RE(j,m)
        {
            REP(k,0,a[j]/b[j])
            {
                int pres = k*c[j];
                if(i>=pres)
                {
                    dp[i][j] = max(dp[i][j], dp[i-pres][j-1] + d[j]*k);
                }
            }
        }
    }
    int ans = 0;
    REP(i,0,n)
        ans = max(ans, dp[i][m] + ((n-i)/c[0])*d[0]);
    cout << ans << "\n";
    return 0;
}
