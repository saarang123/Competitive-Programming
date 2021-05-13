#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
const int mxn = 1000 * 1000 + 2, mxm = 42;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int q; cin >> q;
    while(q--) {
    	int n, m;
    	cin >> n >> m;
    	vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    	vector<int> p(m + 1);
    	for(int i = 1; i <= m; i++)
    		dp[1][i] = 1, p[i] = p[i - 1] + dp[1][i];
	    for(int i = 2; i <= n; i++) {
	    	for(int j = 1; j <= m; j++) {
	    		if(i & 1)
	    			dp[i][j] += (p[m] - p[j + 1]);
	    		else
	    			dp[i][j] += p[j - 1];
	    		if(dp[i][j] >= mod)
	    			dp[i][j] -= mod;
	    	}
	    	for(int j = 1; j <= m; j++) {
	    		p[j] = p[j - 1] + dp[i][j];
	    		if(p[j] >= mod)
	    			p[j] -= mod;
	    	}
	    }
	    cout << dp[n][m] << '\n';
    }
    return 0;
}