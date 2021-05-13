#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

const int mod = 998244353;
const int N = 1e3+5;
ll dp[N][2*N][2][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> k;
    dp[1][1][1][1] = 1;
    dp[1][1][0][0] = 1;
    dp[1][1][0][1] = 0;
    dp[1][1][1][0] = 0;
    dp[1][2][1][0] = 1;
    dp[1][2][0][1] = 1;
    REP(i,2,n)
    {
        REP(j,1,k)
        {
            dp[i][j][1][1] = (dp[i-1][j][1][1] + dp[i-1][j-1][0][0] + dp[i-1][j][0][1] + dp[i-1][j][1][0])%mod;
            dp[i][j][0][0] = (dp[i-1][j-1][1][1] + dp[i-1][j][0][0] + dp[i-1][j][0][1] + dp[i-1][j][1][0])%mod;
            dp[i][j][1][0] = (dp[i-1][j-1][1][1] + dp[i-1][j-1][0][0] + dp[i-1][j-2][0][1] + dp[i-1][j][1][0])%mod;
            dp[i][j][0][1] = (dp[i-1][j-1][1][1] + dp[i-1][j-1][0][0] + dp[i-1][j][0][1] + dp[i-1][j-2][1][0])%mod;
        }
    }
    ll ans = (dp[n][k][0][0] + dp[n][k][1][1] + dp[n][k][1][0] + dp[n][k][0][1])%mod;
    cout << ans << "\n";
    return 0;
}
