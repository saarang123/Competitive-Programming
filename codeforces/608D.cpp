#include<bits/stdc++.h>
const int N = 502;
int dp[N][N], a[N];
void solve_case()
{
    int n,i,j,t,k,m;
    std::cin >> n;
    for(i=1; i<=n; i++)
    {
        std::cin >> a[i];
    }
    for(i=1; i<=n; i++) for(j=1; j<=n; j++) dp[i][j] = 1e8;
    for(i=1; i<=n; i++) dp[i][i] = 1;
    for(i=n; i; i--)
    {
        for(j=i+1; j<=n; j++)
        {
            dp[i][j] = 1e8;
            if(j-i==1)
            {
                if(a[i]==a[j]) dp[i][j] = 1;
                else dp[i][j] = 2;
                continue;
            }
            if(a[i]==a[j]) dp[i][j] = std::min(dp[i][j], dp[i+1][j-1]);
            for(k=i; k<j; k++)
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k+1][j]);
        }
    }
    std::cout << dp[1][n] << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
