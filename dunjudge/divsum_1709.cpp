#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
    	int ans = 0, mx = 0;
    	for(int j = i; j <= n; j += i) {
    		mx += a[j];
    		ans = max(ans, mx);
    		mx = max(mx, 0LL);
    	}
    	dp[i] = ans;
    }
    while(q--) {
    	int t; cin >> t;
    	cout << (t > n ? 0 : dp[t]) << '\n';
    }
    return 0;
}