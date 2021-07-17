#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<bool>> a(n, vector<bool>(m));
    for(int i = 0; i < n; i++) {
    	string s; cin >> s;
    	for(int j = 0; j < m; j++)
    		a[i][j] = s[j] == '1';
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);

    vector<bool> ans(m);
    int best = 0;
    for(int itr = 0; itr < min(n, 50); itr++) {
    	int me = order[itr];
    	vector<int> on;
    	for(int i = 0; i < m; i++)
    		if(a[me][i]) 
    			on.push_back(i);

    	int sz = on.size();
    	vector<int> cnt(1 << sz), dp(1 << sz);
    	for(int i = 0; i < n; i++) {
    		int value = 0;
    		for(int j = 0; j < sz; j++)
    			if(a[i][on[j]])
    				value |= (1 << j);
    		cnt[value]++;
    	}
    	for(int mask = 0; mask < (1 << sz); mask++)
    		for(int smask = mask; smask; smask = (smask - 1) & mask)
    			dp[smask] += cnt[mask];

    	int curbest = 0;
    	for(int mask = 0; mask < (1 << sz); mask++) 
    		if(2 * dp[mask] >= n && __builtin_popcount(mask) > __builtin_popcount(curbest)) 
    			curbest = mask;
    	if(__builtin_popcount(curbest) > best) {
    		best = __builtin_popcount(curbest);
    		ans = vector<bool>(m, false);
    		for(int i = 0; i < sz; i++) 
    			if(curbest >> i & 1)
    				ans[on[i]] = true;
    	}
    }
    for(int i = 0; i < m; i++)
    	cout << ans[i];
    cout << '\n';
    return 0;
}