#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int max3(int a, int b, int c)
{
    return max(max(a,b),c);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> n;
    int dp[3][n+1], a[n+1], h[n+1];
    for(i=1; i<=n; i++)
        cin >> a[i] >> h[i];
    dp[0][n] = 1;
    dp[2][n] = 0;
    dp[1][n] = 0;
    a[0] = -INF, h[0] = -INF;
    if(a[n]-h[n] > a[n-1])
        dp[1][n] = 1;
    for(i=n-1; i>=1; i--)
    {
        if(a[i]+h[i] < a[i+1])
        {
            if(a[i]+h[i] < a[i+1]-h[i+1])
                dp[0][i] = 1 + max3(dp[0][i+1], dp[1][i+1], dp[2][i+1]);
            else
                dp[0][i] = 1 + max(dp[0][i+1], dp[2][i+1]);
        }
        else
            dp[0][i] = max3(dp[0][i+1], dp[1][i+1], dp[2][i+1]);

        if(a[i]-h[i] > a[i-1])
        {
            dp[1][i] = 1 + max3(dp[0][i+1], dp[1][i+1], dp[2][i+1]);
        }
        else
            dp[1][i] = max3(dp[0][i+1], dp[1][i+1], dp[2][i+1]);

        dp[2][i] = max3(dp[0][i+1], dp[1][i+1], dp[2][i+1]);
    }
    /*
    for(j=0; j<3; j++)
    {
        for(i=1; i<=n; i++)
        {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }
    */
    cout << max3(dp[0][1], dp[1][1], dp[2][1]) << "\n";
    return 0;
}
