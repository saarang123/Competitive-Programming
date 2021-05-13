#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j,d,k;
    cin >> n >> k >> d;
    ll dp[2][n+1];
    for(i=0; i<=n; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[0][1] = 1;
    for(i=2; i<=n; i++)
    {
        for(j=1; j<=k; j++)
        {
            if(i-j<0)  continue;
            dp[0][i] += dp[0][i-j];
        }
        dp[0][i] = dp[0][i]%MOD;
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=k; j++)
        {
            if(i-j<0)  continue;
            if(j>=d)
                dp[1][i] += dp[0][i-j];
            else
                dp[1][i] += dp[1][i-j];
        }
        dp[1][i] = dp[1][i]%MOD;
    }
    /*
    for(i=0; i<=n; i++)
        cout << dp[0][i] << " ";
    cout << "\n";
    for(i=0; i<=n; i++)
        cout << dp[1][i] << " ";
    cout << "\n";
    */
    cout << dp[1][n]%MOD << "\n";
    return 0;
}
