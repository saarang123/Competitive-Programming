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
    int n, f;
    cin >> n >> f;
    vector<array<int, 3>> a(n);
    vector<int> c;
    map<array<int, 2>, int> cnt;
    for(auto &[s, e, p] : a) {
    	cin >> s >> e >> p;
    	c.push_back(s); c.push_back(e);
    	cnt[{s, e}] = max(cnt[{s, e}], p);
    }
    sort(a.begin(), a.end());
    auto fix_q = [&] () {
    	vector<int> dp(n);
	    for(int i = n - 1; i >= 0; i--) {
	        dp[i] = a[i][2];
	        for(int j = i + 1; j < n; j++)
	            if(a[i][1] <= a[j][1])
	                dp[i] = max(dp[i], a[i][2] + dp[j]);
	    }
	    return *max_element(dp.begin(), dp.end());
    };
    int x = fix_q(), id = 1;
    sort(c.begin(), c.end());
    n = c.size();
    vector<int> b = c, d(n + 3);
    b.resize(unique(b.begin(), b.end()) - b.begin());
    map<int, int> cc;
    for(int o : b)
    	cc[o] = id++;
    for(int &o : c)
    	o = cc[o];
    vector<vector<int>> cost(n + 3, vector<int>(n + 3));
    vector<vector<int>> dp(n + 3, vector<int>(n + 3));
    for(auto [s, e, p] : a) {
    	cost[cc[s]][cc[e]] = max(cost[cc[s]][cc[e]], p);
    }
    for(int i = n; i; i--) {
    	for(int j = i; j <= n; j++) {
    		dp[i][j] = max({cost[c[i - 1]][c[j - 1]] + dp[i + 1][j - 1], dp[i + 1][j], dp[i][j - 1]});
    	}
    }
    cout << x << ' ' << dp[1][n] << '\n';
    return 0;
}