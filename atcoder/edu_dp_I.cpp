#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e15;
const int N = 3002;
ll dp[N][N][2];
ll a[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i][0] = a[i];
        dp[i][i][1] = -a[i];
    }
    for(int i = n; i; i--) {
        for(int j = i + 1; j <= n; j++) {
            dp[i][j][0] = max(a[i] + dp[i + 1][j][1], a[j] + dp[i][j - 1][1]);
            dp[i][j][1] = min(-a[i] + dp[i + 1][j][0], -a[j] + dp[i][j - 1][0]);
        }
    }
    //for(int i = 1; i <= n; i++) { for(int j = 1; j <= n; j++) cout << dp[i][j][0] << " "; cout << endl; } cout << endl;
    //for(int i = 1; i <= n; i++) { for(int j = 1; j <= n; j++) cout << dp[i][j][1] << " "; cout << endl; }
    cout << dp[1][n][0] << endl;
    return 0;
}
