#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	p[i] = a[i] + p[i - 1];
    }
    auto cost = [&] (int l, int r) {
    	return (p[r] - p[l - 1]) * (p[r] - p[l - 1]);
    };
    vector<vector<int>> dp(k + 1, vector<int> (n + 1, inf));
    dp[0][0] = 0;
    function<void(int i, int l, int r, int optl, int optr)> fix = [&] (int i, int l, int r, int optl, int optr) {
    	if(l > r)
    		return;
    	int mid = (l + r) >> 1, opt = -1;
    	dp[i][mid] = inf;
    	for(int m = optl; m <= min(mid, optr); m++) 
    		if(dp[i][mid] > dp[i - 1][m] + cost(m + 1, mid)) {
    			dp[i][mid] = dp[i - 1][m] + cost(m + 1, mid);
    			opt = m;
    		}
    	fix(i, l, mid - 1, optl, opt);
    	fix(i, mid + 1, r, opt, optr);
    };
    for(int i = 1; i <= k; i++)
    	fix(i, 1, n, 0, n);
    cout << dp[k][n] << '\n';
    return 0;
}