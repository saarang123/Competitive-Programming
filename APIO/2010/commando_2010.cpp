#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
struct Line {
    int slope, c; //slope, yIntercept
    Line() {
    	slope = 0; c = -inf;
    }
    Line(int Slope, int C) : slope(Slope), c(C) {}
    int operator () (int xCoordinate) { return slope * xCoordinate + c; }  //y coordinate
    int intersect(Line other) {  //ceiling of x coordinate of intersection
        return (other.c - c + slope - other.slope - 1) / (slope - other.slope);
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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> h(n + 1), dp(n + 1, -inf);
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
    	cin >> h[i], h[i] += h[i - 1];
    deque<Line> dq;
    dq.push_back({0, 0});
    for(int i = 1; i <= n; i++) {
    	while(dq.size() > 1 && dq.back()(h[i]) <= dq[dq.size() - 2](h[i]))
    		dq.pop_back();
    	dp[i] = a * h[i] * h[i] + b * h[i] + c + dq.back()(h[i]);
    	Line nxt = {-2 * a * h[i], a * h[i] * h[i] - b * h[i] + dp[i]};
    	while(dq.size() > 1 && nxt.intersect(dq[0]) <= dq[0].intersect(dq[1]))
    		dq.pop_front();
    	dq.push_front(nxt);
    }
    cout << dp[n] << '\n';
    return 0;
}