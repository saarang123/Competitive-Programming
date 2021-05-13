#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int inf = 1000 * 1000 * 1000;
int dp[N][N][27];
int cost[27][27];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m, k, i, j;
    string s;
    cin >> s >> k >> m;
    n = s.size();
    for(i = 0; i < m; i++) {
        char a, b;
        cin >> a >> b >> j;
        cost[a - 'a'][b - 'a'] = j;
    }
    s = " " + s;
    for(i = 0; i <= n; i++) for(int j = 0; j <= k; j++) for(int c = 0; c < 26; c++) dp[i][j][c] = -inf;
    for(int c = 0; c < 26; c++) if(c != s[1] - 'a') dp[1][1][c] = 0;
    dp[1][0][s[1] - 'a'] = 0;
    for(i = 2; i <= n; i++) {
        for(j = 0; j <= k; j++) {
            for(int c = 0; c < 26; c++) {
                for(int p = 0; p < 26; p++) {
                    if(c == s[i] - 'a') {
                        dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][p] + cost[p][c]);
                        continue;
                    }
                    if(j) dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j - 1][p] + cost[p][c]);
                }
            }
        }
    }
    int ans = -inf;
    for(j = 0; j <= k; j++) for(int c = 0; c < 26; c++) ans = max(ans, dp[n][j][c]);
    cout << ans << endl;
    return 0;
}
