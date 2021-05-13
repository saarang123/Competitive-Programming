#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, x, y;
    cin >> n >> x >> y;
    if(x > y)
        swap(x, y);
    string s; cin >> s;
    s = " " + s;
    vector<int> p(n + 1), dp(n + 1);
    for(int i = 1; i <= n; i++)
    	p[i] = p[i - 1] + (s[i] == '0');
    for(int i = 0; i < x; i++)
    	dp[i] = i - p[i];
    deque<array<int, 2>> dq;
    for(int i = x; i <= n; i++) {
    	while(!dq.empty() && dq.front()[1] < i - y)
    		dq.pop_front();
    	if(i - x >= 0) {
    		while(!dq.empty() && dq.back()[0] >= dp[i - x] - p[i - x])
    			dq.pop_back();
    		dq.push_back({dp[i - x] - p[i - x], i - x});
    	}
    	dp[i] = min(dq.front()[0] + p[i], (s[i] != '0') + dp[i - 1]);
    }
    cout << dp[n] << '\n';
    return 0;
}