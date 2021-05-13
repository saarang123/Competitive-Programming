#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
ll a[300005], b[300005], dp[3][300005];

ll min3(ll a, ll b, ll c)
{
    return min(a,min(b,c));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)
        {
            cin >> a[i] >> b[i];
        }
        //memset(dp, INF, sizeof dp);
        dp[0][n] = 0;
        dp[1][n] = b[n];
        dp[2][n] = 2*b[n];
        for(i=n-1; i>0; i--)
        {
            for(j=2; j>=0; j--)
            {
                if(a[i]+j == a[i+1])
                    dp[j][i] = j*b[i] + min(dp[1][i+1], dp[2][i+1]);
                else if(a[i]+j == a[i+1]+1)
                    dp[j][i] = j*b[i] + min(dp[0][i+1], dp[2][i+1]);
                else if(a[i]+j == a[i+1]+2)
                    dp[j][i] = j*b[i] + min(dp[0][i+1], dp[1][i+1]);
                else
                    dp[j][i] = j*b[i] + min3(dp[0][i+1], dp[1][i+1], dp[2][i+1]);
            }
        }
        dp[0][0] = min3(dp[0][1], dp[1][1], dp[2][1]);
        /*
        for(i=0; i<=2; i++)
        {
            for(j=1; j<=n; j++)
                cout << dp[i][j] << " ";
            cout << "\n";
        }
        */
        cout << dp[0][0] << "\n";
    }
    return 0;

}
