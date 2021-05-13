#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3;
int seg[2 * mxn], l[mxn], r[mxn], a[mxn], p[mxn], dp[mxn][103], n, k, mx = 0;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    for(int i = 0; i <= n; i++)
    	for(int j = 0; j <= n; j++)
    		dp[i][j] = 1e9;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	l[i] = r[i] = i;
    	l[i] = r[i] = i;
    	mx = max(mx, a[i]);
    	dp[1][i] = mx;
    }
    stack<int> s;
    for(int i = 1; i <= n; i++) {
    	while(!s.empty() && a[s.top()] <= a[i])
    		s.pop();
    	l[i] = s.empty() ? 1 : s.top() + 1;
    	s.push(i);
    }
    while(!s.empty()) s.pop();
    for(int i = n; i; i--) {
    	while(!s.empty() && a[s.top()] <= a[i])
    		s.pop();
    	r[i] = s.empty() ? n : s.top() - 1;
    	s.push(i);
    }
    // for(int i = 1; i <= n; i++)
    // 	cout << l[i] << ' ' << r[i] << '\n';
    auto query = [&] (int i, int j) {
    	int res = 1e9;
    	i = max(1, i);
    	if(i > j) return res;
    	for(i += n - 1, j += n; i < j; i >>= 1, j >>= 1) {
    		if(i & 1)
    			res = min(res, seg[i++]);
    		if(j & 1)
    			res = min(res, seg[--j]);
    	}
    	return res;
    };
    for(int i = 2; i <= k; i++) {
    	for(int j = 1; j <= n; j++)
    		seg[n + j - 1] = dp[i - 1][j];
    	for(int j = n - 1; j > 0; j--)
    		seg[j] = min(seg[j << 1], seg[j << 1|1]);
    	for(int j = i; j <= n; j++) {
    		dp[i][j] = min(dp[i][j], a[j] + query(l[j] - 1, j - 1));
    		dp[i][r[j]] = min(dp[i][r[j]], a[j] + query(l[j] - 1, j - 1));
    	}
    }
    // for(int i = 1; i <= k; i++) {
    // 	for(int j = 1; j <= n; j++)
    // 		cout << dp[i][j] << ' ';
    // 	cout << '\n';
    // }
    cout << dp[k][n] << '\n';
    return 0;
}