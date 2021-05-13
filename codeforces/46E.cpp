#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1502;
const int inf = 1e10;
int dp[N][N];
vector<int> pref(N), suf(N);
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= m; j++) {
            int x; cin >> x;
            sum += x;
            if(i & 1) dp[i][j] = pref[j - 1] + sum;
            else dp[i][j] = suf[j + 1] + sum;
        }
        pref[0] = - inf;
        suf[m + 1] = -inf;
        for(int j = 1; j <= m; j++) pref[j] = max(pref[j - 1], dp[i][j]);
        for(int j = m; j; j--) suf[j] = max(suf[j + 1], dp[i][j]);
    }
    int ans = -inf;
    for(int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';
    return 0;
}
