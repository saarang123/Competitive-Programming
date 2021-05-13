#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 5002;
const ll inf = 1e18;
vector<int> a(N);
vector<vector<ll>> dp(N, vector<ll>(N));
vector<array<int, 2>> t(N);
int n, m;
void solve_case() {
    int i, j;
    cin >> n >> m;
    for(i = 1; i <= n; i++) cin >> a[i];
    for(i = 1; i <= m; i++) cin >> t[i][1];
    for(i = 1; i <= m; i++) cin >> t[i][0];
    sort(t.begin() + 1, t.begin() + m + 1);
    dp[0][0] = 0;
    for(i = 1; i <= m; i++) {
        dp[0][i] = inf;
        if(dp[0][i - 1] < t[i][0]) dp[0][i] = min(dp[0][i], max(dp[0][i - 1] + t[i][1], (ll) t[i][0]));
    }
    for(i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + a[i];
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            dp[i][j] = inf;
            if(dp[i][j - 1] < t[j][0])
                dp[i][j] = min(dp[i][j], max(dp[i][j - 1] + t[j][1], (ll) t[j][0]));
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
        }
    }
    cout << (dp[n][m] >= inf ? -1 : dp[n][m]) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
