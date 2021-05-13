#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 5002;
const int inf = 1e10;
int dp[N][N], pref[N], suf[N];
bool g[N][N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= c; i++) {
    	string s; cin >> s;
    	for(int j = 0; j < n; j++) g[j + 1][i] = (s[j] - '0');
    }
    for(int i = 1; i <= c; i++) dp[1][i] = (g[1][i] ? 0 : inf);
    pref[1] = dp[1][1] - 1; suf[c] = dp[1][c] + c;
	for(int i = 2; i <= c; i++) pref[i] = min(pref[i - 1], dp[1][i] - i);
	for(int i = c - 1; i; i--) suf[i] = min(suf[i + 1], dp[1][i] + i);
    for(int i = 2; i <= n; i++) {
    	for(int j = 1; j <= c; j++) {
    		dp[i][j] = inf;
    		if(!g[i][j]) continue;
    		dp[i][j] = min(dp[i][j], pref[j] + j);
    		dp[i][j] = min(dp[i][j], suf[j] - j);
;    	}
		pref[1] = dp[i][1] - 1; suf[c] = dp[i][c] + c;
		for(int j = 2; j <= c; j++) pref[j] = min(pref[j - 1], dp[i][j] - j);
		for(int j = c - 1; j; j--) suf[j] = min(suf[j + 1], dp[i][j] + j);
    }
    int ans = inf;
    for(int i = 1; i <= c; i++) ans = min(ans, dp[n][i]);
    cout << ans << '\n';
    return 0;
}