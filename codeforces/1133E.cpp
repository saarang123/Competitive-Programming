#include<bits/stdc++.h>

const int N = 5e3+2;
int a[N], dp[N][N];
void solve_case()
{
    int n,i,j,t,k,m;
    std::cin >> n >> k;
    for(i=0; i<n; i++) std::cin >> a[i];
    std::sort(a, a+n);
    for(int l=0, r=0; l<n; l++)
    {
        while(r<n && a[r]-a[l]<=5) r++;
        for(i=0; i<=k; i++)
        {
            dp[l+1][i] = std::max(dp[l][i], dp[l+1][i]);
            if(i) dp[r][i] = std::max(dp[r][i], dp[l][i-1] + r-l);
        }
    }
    std::cout << dp[n][k] << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
