#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

const int N = 502;
const int M = 5002;
bitset<N> a[N];
bitset<N> dp[N][M];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m, k, i, j;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) for(j = 1; j <= m; j++) {
        char c; cin >> c;
        if(c == '.') dp[i][0][j] = a[i][j] = true;
    }
    string s;
    cin >> s;
    for(int x = 0; x < k; x++) {
        if(s[x] == 'N') {
            for(i = 1; i < n; i++) dp[i][x + 1] |= (dp[i + 1][x] & a[i]);
        }
        else if(s[x] == 'S') {
            for(i = 2; i <= n; i++) dp[i][x + 1] |= (dp[i - 1][x] & a[i]);
        }
        else if(s[x] == 'E') {
            for(i = 1; i <= n; i++) dp[i][x + 1] |= ((dp[i][x] << 1) & a[i]);
        }
        else if(s[x] == 'W') {
            for(i = 1; i <= n; i++) dp[i][x + 1] |= ((dp[i][x] >> 1) & a[i]);
        }
        else {
            for(i = 1; i <= n; i++) dp[i][x + 1] |= (((dp[i][x] >> 1) | (dp[i][x] << 1) | dp[i + 1][x] | dp[i - 1][x]) & a[i]);
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) for(j = 1; j <= m; j++) ans += dp[i][k][j];
    cout << ans << "\n";
    return 0;
}
