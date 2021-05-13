#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 20;
int n, dp[N][N], ten[N];
string s;

int f(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    if(i == 0 && j == 0) return dp[i][j] = 0;
    if(i == 0) return dp[i][j] = (s[i + j] - '0') * ten[n - j] + f(i, j - 1);
    if(j == 0) return dp[i][j] = (s[i + j] - '0') * ten[n - i] + f(i - 1, j);
    return dp[i][j] = max((s[i + j] - '0') * ten[n - j] + f(i, j - 1), (s[i + j] - '0') * ten[n - i] + f(i - 1, j));
}

string out(int i, int j) {
    if(i == 0 && j == 0) return "";
    if(i == 0) return "M" + out(i, j - 1);
    if(j == 0) return "H" + out(i - 1, j);
    if(dp[i][j] == (s[i + j] - '0') * ten[n - i] + dp[i - 1][j])
        return "H" + out(i - 1, j);
    return "M" + out(i, j - 1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    ten[0] = 1;
    for(int i = 1; i < N; i++) ten[i] = 10 * ten[i - 1];
    cin >> n >> s;
    s = " " + s;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dp[i][j] = -1;
    f(n, n);
    string ans = out(n, n);
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    return 0;
}
