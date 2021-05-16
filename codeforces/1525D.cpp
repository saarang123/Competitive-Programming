#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 2e9));
    dp[0] = vector<int> (n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(!a[i]) {
            dp[i] = dp[i - 1];
            continue;
        }
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if(!a[j])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(j - i));
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
    return 0;
}