#include <bits/stdc++.h>
using namespace std;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> a(n);
    for(int &x : a)
    	cin >> x;
    if(p + q >= n)
    	return cout << 1 << '\n', 0;
    sort(a.begin(), a.end());
    auto check = [&] (int k) {
    	vector<vector<int>> dp(n, vector<int> (p + 1));
    	int p1 = 0, p2 = 0;
    	for(int i = 0; i < n; i++) {
    		while(a[i] - a[p1] >= k)
    			p1++;
    		while(a[i] - a[p2] >= 2 * k)
    			p2++;
    		for(int j = 0; j <= p; j++) {
    			if(j) {
    				if(p1 == 0) 
    					dp[i][j] = 0;
    				else if(p2 == 0)
    					dp[i][j] = min(1, dp[p1 - 1][j - 1]);
    				else
    					dp[i][j] = min(dp[p1 - 1][j - 1], dp[p2 - 1][j] + 1);
    			} else {
    				if(p2 == 0)
    					dp[i][j] = 1;
    				else
    					dp[i][j] = dp[p2 - 1][j] + 1;
    			}
    		}
    	}
    	return *min_element(dp[n - 1].begin(), dp[n - 1].end()) <= q;
    };
    int mn = 1, mx = 1000 * 1000 * 1000 + 3;
    while(mn < mx) {
    	int mid = (mn + mx) >> 1;
    	if(check(mid))
    		mx = mid;
    	else
    		mn = mid + 1;
    }
    cout << mn << '\n';
    return 0;
}
