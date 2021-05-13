#include <bits/stdc++.h>
using namespace std;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n + 2, vector<int> (m + 2)), a(n + 2, vector<int> (m + 2));
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }
    vector<int> p(m + 2), suf(m + 2);
    auto sum = [&] (int i, int j) { return a[i][j + k - 1] - a[i][j - 1]; };
    auto range = [&] (int i, int x, int y) {
        return a[i][x + k - 1] - a[i][x - 1] + a[i][y + k - 1] - a[i][y - 1] - max(0, a[i][x + k - 1] - a[i][y - 1]);
    };
    auto build = [&] (int id) {
        for(int i = 1; i + k - 1 <= m; i++)
            p[i] = max(p[i - 1], dp[id][i] + sum(id + 1, i));
        for(int i = m - k + 1; i; i--)
            suf[i] = max(suf[i + 1], dp[id][i] + sum(id + 1, i));
    };
    for(int i = 1; i + k - 1 <= m; i++)
        dp[1][i] = sum(1, i);
    for(int i = 2; i <= n; i++) {
        build(i - 1);
        for(int j = 1; j + k - 1 <= m; j++) {
            dp[i][j] = max(dp[i][j], sum(i, j) + suf[j + k]);
            if(j - k > 0)
                dp[i][j] = max(dp[i][j], sum(i, j) + p[j - k]);
            for(int id = max(1, j - k + 1); id <= min(j + k - 1, m) && id + k - 1 <= m; id++)
                dp[i][j] = max(dp[i][j], dp[i - 1][id] + range(i, min(j, id), max(j, id)));
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
    return 0;
}