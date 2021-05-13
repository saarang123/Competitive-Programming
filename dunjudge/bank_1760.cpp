#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 1e6 + 4;
int dp[N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<int> cost;
    for(int k : {6, 9}) {
    	int c = k;
    	while(c <= n) {
    		cost.push_back(c);
    		c *= k;
    	}
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
    	dp[i] = 1 + dp[i - 1];
    	for(int j : cost) 
    		if(i - j >= 0)
    			dp[i] = min(dp[i], 1 + dp[i - j]);
    }
    cout << dp[n] << '\n';
    return 0;
}