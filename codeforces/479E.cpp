#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
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

const ll N = 5005;
const ll mod = 1e9+7;
ll dp[N][N] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,i,j,t,k,m,a,b;
    cin >> n >> a >> b >> k;
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=k; j++)
        {
            dp[i][j] = 0;
        }
    }

    //initializing row k
    for(i=1; i<=n; i++)
    {
        dp[i][k] = dp[i-1][k];
        if(i!=b) dp[i][k]++;
        dp[i][k] = dp[i][k]%mod;
    }
    for(j=k-1; j>=0; j--)
    {
        for(i=1; i<=n; i++)
        {
            if(i==b)
            {
                dp[i][j] = dp[i-1][j];
                continue;
            }

            ll p = abs(i-b)-1;  //possible floors u can move to
            ll samefloor = (dp[i][j+1] - dp[i-1][j+1])%mod;  //samefloor combinations for j+1th move
            dp[i][j] = (dp[i-1][j] + (dp[min(i+p,n)][j+1]-dp[max(i-p,(ll)1)-1][j+1])%mod -samefloor)%mod;  //dp idk
            if(dp[i][j]<0) dp[i][j]+=mod;
        }
    }

    /*
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=k; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    ll ans = (dp[a][0]-dp[a-1][0])%mod;
    if(ans<0) ans+=mod;
    cout << ans << "\n";
    return 0;
}
