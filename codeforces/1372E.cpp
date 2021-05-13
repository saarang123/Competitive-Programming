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
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> a(m + 1);
    for(int _ = 0; _ < n; _++) {
    	int k; cin >> k;
    	while(k--) {
    		int l, r;
    		cin >> l >> r;
    		for(int x = l; x <= r; x++)
    			a[x].push_back({l, r});
    	}
    }
    vector<vector<int>> dp(m + 2, vector<int> (m + 2));
    for(int i = m; i; i--) {
    	for(int j = i; j <= m; j++) {
    		for(int c = i; c <= j; c++) {
    			int cnt = 0;
    			for(auto &in : a[c])
    				cnt += (i <= in[0] && in[1] <= j);  //optimal to fill row c
    			dp[i][j] = max(dp[i][j], dp[i][c - 1] + cnt * cnt + dp[c + 1][j]);
    		}
    	}
    }
    cout << dp[1][m] << '\n';
    return 0;
}