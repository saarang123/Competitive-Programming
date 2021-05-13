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
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    auto best = [&] (vector<int> h) {
        int ans = 0, i = 1;
        stack<int> s;
        while(i <= m) {
            if(s.empty() || h[s.top()] <= h[i]) 
                s.push(i++);
            else {
                int md = s.top(); s.pop();
                ans = max(ans, (s.empty() ? i - 1 : i - s.top() - 1) * h[md]);
            }
        }
        while(!s.empty()) {
            int md = s.top(); s.pop();
            ans = max(ans, (s.empty() ? i - 1 : i - s.top() - 1) * h[md]);
        }
        return ans;
    };
    auto check = [&] (int k) {
        vector<vector<int>> dp(n + 2, vector<int>(m + 2));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) 
                dp[i][j] = (a[i][j] > k) * (dp[i - 1][j] + 1);
        int area = 0;
        for(int i = 1; i <= n; i++) {
            area = max(area, best(dp[i]));
        }
        return area >= t;
    };
    int mn = 0, mx = 1e9;
    while(mn < mx) {
        int mid = (mn + mx + 1) >> 1;
        if(check(mid)) mn = mid;
        else mx = mid - 1;
    }
    cout << mn << '\n';
    return 0;
}