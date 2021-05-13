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
    vector<int> p(m + 2), suf(m + 2);
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
        }

    auto sum = [&] (int i, int j) { return a[i][j + k - 1] - a[i][j - 1]; };
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
        deque<array<int, 2>> dq;
        for(int j = 1; j + k - 1 <= m; j++) {
            if(j - k > 0)
                dp[i][j] = max(dp[i][j], sum(i, j) + p[j - k]);
            while(!dq.empty() && dq.back()[0] <= dp[i - 1][j] + (a[i][m] - a[i][j - 1]))
                dq.pop_back();
            dq.push_back({dp[i - 1][j] + (a[i][m] - a[i][j - 1]), j});
            while(!dq.empty() && dq.front()[1] < j - k + 1)
                dq.pop_front();
            dp[i][j] = max(dp[i][j], dq.front()[0] - (a[i][m] - a[i][j + k - 1]));
        }

        dq.clear();
        for(int j = m - k + 1; j > 0; j--) {
            dp[i][j] = max(dp[i][j], sum(i, j) + suf[j + k]);
            while(!dq.empty() && dq.back()[0] <= dp[i - 1][j] + a[i][j + k - 1])
                dq.pop_back();
            dq.push_back({dp[i - 1][j] + a[i][j + k - 1], j});
            while(!dq.empty() && dq.front()[1] > j + k - 1)
                dq.pop_front();
            dp[i][j] = max(dp[i][j], dq.front()[0] - a[i][j - 1]);
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
    return 0;
}