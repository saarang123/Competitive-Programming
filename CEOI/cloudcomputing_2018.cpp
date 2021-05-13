#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int sum = 0;
    vector<array<int, 3>> cost;
    for(int _ = 0; _ < 2; _++) {
    	int n; cin >> n;
    	for(int i = 0; i < n; i++) {
    		int c, f, v;
    		cin >> c >> f >> v;
    		if(_ == 0) v *= -1, sum += c;
    		else c *= -1;
    		cost.push_back({f, c, v});
    	}
    }
    sort(cost.begin(), cost.end());
    reverse(cost.begin(), cost.end());
    long long dp[2][sum + 2];
    for(int i = 0; i <= sum; i++) dp[0][i] = -inf;
    dp[0][0] = 0;
    for(auto &[freq, core, value] : cost) {
    	for(int i = 0; i <= sum; i++) dp[1][i] = dp[0][i];
    	for(int i = 0; i <= sum; i++) {
    		int total = i + core;
    		long long profit = dp[0][i] + value;
    		if(total >= 0 && total <= sum)
    			dp[1][total] = max(dp[1][total], profit);
    	}
    	for(int i = 0; i <= sum; i++) dp[0][i] = dp[1][i];
    }
    cout << *max_element(dp[0], dp[0] + sum) << '\n';
    return 0;
}