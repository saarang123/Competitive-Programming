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
    int n; cin >> n;
    vector<int> h(n), dp(n, n);
    for(int &x : h)
    	cin >> x;
    vector<vector<int>> g(n);
    deque<array<int, 2>> stk;
    for(int i = 0; i < n; i++) {
    	while(!stk.empty() && stk.back()[0] < h[i]) //greater on left
    		stk.pop_back();
    	if(!stk.empty()) 
    		g[stk.back()[1]].push_back(i);
    	stk.push_back({h[i], i});
    }
    stk.clear();
    for(int i = 0; i < n; i++) {
    	while(!stk.empty() && stk.back()[0] > h[i])  //lesser on left
    		stk.pop_back();
    	if(!stk.empty())
    		g[stk.back()[1]].push_back(i);
    	stk.push_back({h[i], i});
    }
    stk.clear();
    for(int i = n - 1; i >= 0; i--) {
    	while(!stk.empty() && stk.back()[0] < h[i])  //greater on right
    		stk.pop_back();
    	if(!stk.empty())
    		g[i].push_back(stk.back()[1]);
    	stk.push_back({h[i], i});
    }
    stk.clear();
    for(int i = n - 1; i >= 0; i--) {
    	while(!stk.empty() && stk.back()[0] > h[i]) //lesser on right
    		stk.pop_back();
    	if(!stk.empty())
    		g[i].push_back(stk.back()[1]);
    	stk.push_back({h[i], i});
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    	for(int to : g[i])
    		dp[to] = min(dp[to], dp[i] + 1);
    cout << dp.back() << '\n';
    return 0;
}