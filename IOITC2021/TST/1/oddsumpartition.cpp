#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

void solve_case() {
    int n; cin >> n;
    int dp[n], a[n];
    for(int i = 0; i < n; i++) {
    	char c; cin >> c;
    	a[i] = c - '0';
    	if(i)
    		a[i] += a[i - 1];
    	if(a[i] >= 2)
    		a[i] -= 2;
    }
    for(int m = 1; m <= n; m++) {
    	deque<array<int, 2>> dq[2];
    	memset(dp, 0x2f, sizeof dp);
    	dq[0].push_back({0, -1});
    	for(int i = 0; i < n; i++) {
    		int o = a[i] ^ 1;
    		while(!dq[o].empty() && i - dq[o].front()[1] > m)
    			dq[o].pop_front();
    		if(!dq[o].empty())
    			dp[i] = 1 + dq[o].front()[0];
    		while(!dq[a[i]].empty() && dq[a[i]].back()[0] >= dp[i])
    			dq[a[i]].pop_back();
    		if(dp[i] <= n)
    			dq[a[i]].push_back({dp[i], i});
    	}
    	cout << (dp[n - 1] > n ? -1 : dp[n - 1]) << ' ';
    }
    cout << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

