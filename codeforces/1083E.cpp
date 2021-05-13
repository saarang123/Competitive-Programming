#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e15;

struct Line {
	int m, c;
	Line() {
		m = 0;
		c = inf;
	}
	Line(int _m, int _c) : m(_m), c(_c) {}
	int operator () (int x) {
		return m * x + c;
	}
	long double intersect(const Line other) {
		return ((long double) other.c - c) / ((long double) m - other.m);
	}
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<array<int, 3>> a(n);
    for(auto &[x, y, v] : a)
    	cin >> x >> y >> v;
    sort(a.begin(), a.end());
    vector<int> dp(n);
    deque<Line> dq;
    dq.push_back({0, 0});
    int ans = 0;
    for(int i = 0; i < n; i++) {
    	while(dq.size() > 1 && dq.back()(a[i][1]) <= dq[dq.size() - 2](a[i][1]))
    		dq.pop_back();
    	dp[i] = a[i][0] * a[i][1] - a[i][2] + dq.back()(a[i][1]);
    	ans = max(ans, dp[i]);
    	Line nxt = {-a[i][0], dp[i]};
    	while(dq.size() > 1 && nxt.intersect(dq[0]) >= dq[0].intersect(dq[1]))
    		dq.pop_front();
    	dq.push_front(nxt);
    }
    cout << ans << '\n';
    return 0;
}