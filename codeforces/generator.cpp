#pragma GCC optimize("-O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define endl "\n"
#define mod 1000000007
#define inf 0xFFFFFFFFFFFFFFFL
 
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> coins(n), dp(k + 1);
 
    for (int i = 0; i < n; i++)
        cin >> coins[i];
 
    sort(coins.begin(), coins.end());
 
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] += dp[i - coins[j]];
                if(dp[i] >= mod)
                    dp[i] -= mod;
            }
            else
                break;
        }
    }
    cout << dp[k] << endl;
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}