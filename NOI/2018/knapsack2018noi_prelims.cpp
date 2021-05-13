#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e15, N = 2002;
vector<array<int, 2>> a[N];
int ans = 0;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, s;
    cin >> s >> n;
    for(int w, c, k, i = 0; i < n; i++) {
    	cin >> c >> w >> k;
    	k = min(k, s / w);
    	a[w].push_back({c, k});
    }
    vector<array<int, 2>> costs;
    for(int i = 1; i <= s; i++) sort(a[i].begin(), a[i].end(), greater<>());
    for(int i = 1; i <= s; i++) {
    	int left = s / i;
    	for(auto x : a[i]) {
    		int c = x[0], k = x[1];
    		for(int j = 0; j < k && left > 0; j++, left--) {
    			costs.push_back({i, c});
    		}
    	}
    }
    n = costs.size();
    vector<vector<int>> dp(n + 2, vector<int>(s + 2, -inf));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
    	for(int j = 0; j <= s; j++) {
    		dp[i][j] = dp[i - 1][j];
    		if(j - costs[i - 1][0] >= 0)
    			dp[i][j] = max(dp[i][j], dp[i - 1][j - costs[i - 1][0]] + costs[i - 1][1]);
    		ans = max(ans, dp[i][j]);
    	}
    }
    cout << ans << '\n';
    return 0;
}