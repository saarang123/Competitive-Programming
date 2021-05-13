#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 3 * 100 * 1000 + 3;
int a[mxn], p[mxn], n, k;

array<int, 2> check(int m) {
	vector<int> dp(n + 1), cnt(n + 1);
	int j = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1], cnt[i] = cnt[i - 1];
        if (dp[i] < dp[j] + p[i] - p[j] - m) {
            dp[i] = dp[j] + p[i] - p[j] - m;
            cnt[i] = cnt[j] + 1;
        }
        if (dp[j] - p[j] < dp[i] - p[i]) j = i;
    }
	return {dp[n], cnt[n]};
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	p[i] = p[i - 1] + a[i];
    }
    int mn = 0, mx = 1e18;
    while(mn < mx) {
    	int mid = (mn + mx) >> 1;
    	if(check(mid)[1] > k)
    		mn = mid + 1;
    	else
    		mx = mid;
    }
    cout << check(mn)[0] + mn * k << '\n';
    return 0;
}