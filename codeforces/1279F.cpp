#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000 * 1000 + 3;
int n, k, l;
bool a[mxn];

pair<int, int> check(int cost) {
	vector<int> dp(n + 1);
	vector<int> cnt(n + 1);
	dp[0] = cnt[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + a[i];
		cnt[i] = cnt[i - 1];
		if(i >= l && dp[i - l] + cost < dp[i]) {
			dp[i] = dp[i - l] + cost;
			cnt[i] = cnt[i - l] + 1;
		}
	}
	return {dp[n], cnt[n]};
}

int solve() {
    int mn = 0, mx = 1e9;
    while(mn < mx) {
    	int mid = (mn + mx) / 2;
    	auto dp = check(mid);
    	if(dp.second > k)
    		mn = mid + 1;
    	else
    		mx = mid;
    }
    return check(mn).first - k * mn * 1LL;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> k >> l;
    if((long long) k * l >= n)
    	return cout << 0 << '\n', 0;
    for(int i = 1; i <= n; i++) {
    	char c; cin >> c;
    	a[i] = ('a' <= c && c <= 'z');
    }
    int ans = solve();
    for(int i = 1; i <= n; i++)
    	a[i] ^= 1;
    ans = min(ans, solve());
    cout << ans << '\n';
    return 0;
}