#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 502;
int dp[N][N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;
    for(int i = n; i; i--) {
        for(int j = i; j <= n; j++) {
            if(i == j) dp[i][j] = 1;
            else {
                dp[i][j] = 1 + dp[i + 1][j];
                for(int k = i + 1; k <= j; k++)
                    if(s[k] == s[i])
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}