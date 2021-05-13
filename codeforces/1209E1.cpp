#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++)
		for(int &x : a[i])
			cin >> x;
	vector<vector<int>> dp(m + 1, vector<int>(1 << n));
	for(int i = 1; i <= m; i++) {
		vector<int> cost(1 << n);
		for(int mask = 0; mask < (1 << n); mask++) {
			for(int j = 0; j < n; j++) {
				int sum = 0;
				for(int k = 0; k < n; k++)
					if(mask >> k & 1)
						sum += a[(j + k) % n][i - 1];
				cost[mask] = max(cost[mask], sum);
			}
			dp[i][mask] = dp[i - 1][mask];
			for(int smask = mask; smask; smask = (smask - 1) & mask)
				dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ smask] + cost[smask]);
		}
	}
	cout << dp[m][(1 << n) - 1] << '\n';
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tc; cin >> tc;
    while(tc--)
    	solve();
    return 0;
}