#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 1000 + 3;
const int inf = 1e15;
vector<vector<int>> dp(N, vector<int>(N, inf));
//dp[i][time] - min cost to buy first i items with time second left.

int f(int x) { return min(N - 1, x); }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0];
    }
    sort(a.begin(), a.end());
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int time = 0; time < N - 1; time++) {
            dp[i][time] = min(dp[i][time], dp[i - 1][time + 1]);
            dp[i][time] = min(dp[i][time], dp[i - 1][time] + a[i - 1][0]);
            dp[i][a[i - 1][1]] = min(dp[i][a[i - 1][1]], dp[i - 1][time] + a[i - 1][0]);
            if(a[i - 1][1] >= i - 1)
                dp[i][a[i - 1][1] - i + 1] = min(dp[i][a[i - 1][1] - i + 1], a[i - 1][0]);
            dp[i][f(time + a[i - 1][1])] = min(dp[i][f(time + a[i - 1][1])], dp[i - 1][time] + a[i - 1][0]);
        }
    }
    //for(int i = 0; i <= n; i++) { for(int j = 0; j <= 20; j++) cout << (dp[i][j] >= inf ? -1 : dp[i][j]) << " "; cout << endl; }
    int ans = inf;
    for(int time = 0; time < N; time++) ans = min(ans, dp[n][time]);
    cout << ans << endl;
    return 0;
}
