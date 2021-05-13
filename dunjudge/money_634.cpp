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
    int n, t;
    cin >> n >> t;
    vector<array<int, 3>> a(n);
    for(auto &[timer, tile, money] : a)
    	cin >> money >> tile >> timer;
    a.push_back({0, 0, 0});
    sort(a.begin(), a.end());
    vector<int> dp(n + 1);
    for(int i = n; i >= 0; i--) {
    	dp[i] = a[i][2];
    	for(int j = i + 1; j <= n; j++)
    		if(a[i][0] + abs(a[i][1] - a[j][1]) <= a[j][0])
    			dp[i] = max(dp[i], dp[j] + a[i][2]);
    }
    cout << dp[0] << '\n';
    return 0;
}