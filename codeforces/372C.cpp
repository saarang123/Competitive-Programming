#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int mxm = 302, mxn = 150002;
long long dp[2][mxn];
int a[mxm], b[mxm], t[mxm];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    long long d;
    cin >> n >> m >> d;
    for(int i = 1; i <= m; i++)
    	cin >> a[i] >> b[i] >> t[i];
    for(int i = 1; i <= n; i++)
    	dp[1][i] = b[1] - abs(a[1] - i);

    for(int i = 2; i <= m; i++) {
    	deque<array<long long, 2>> dq;
    	int r = 2;
    	for(int j = 1; j <= n; j++) {
    		while(!dq.empty() && dq.back()[0] <= dp[(i & 1) ^ 1][j])
    			dq.pop_back();
    		dq.push_back({dp[(i & 1) ^ 1][j], j});
    		int right = min((long long) n, j + d * (t[i] - t[i - 1]));
    		while(r <= right) {
    			while(!dq.empty() && dq.back()[0] <= dp[(i & 1) ^ 1][r])
    				dq.pop_back();
    			dq.push_back({dp[(i & 1) ^ 1][r], r++});
    		}
    		while(!dq.empty() && dq.front()[1] < (j - d * (t[i] - t[i - 1])))
    			dq.pop_front();
    		dp[i & 1][j] = dq.front()[0] + b[i] - abs(a[i] - j);
    	}
    }

    long long answer = -inf;
    for(int i = 1; i <= n; i++)
    	answer = max(answer, dp[m & 1][i]);
    cout << answer << '\n';
    return 0;
}