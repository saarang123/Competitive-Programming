#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 402;
int dp[2][N][N], mn[2][N];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    for(int k = 0; k < 2; k++)
    	for(int i = 0; i <= m; i++) {
    		for(int j = 0; j <= n; j++)
    			dp[k][i][j] = inf;
    		mn[k][i] = inf;
    	}
    for(int i = 1; i <= n; i++) {
    	if(a[i] >= a[1])
    		dp[1][0][i] = a[i] - a[1];
    	mn[1][0] = min(mn[1][0], dp[1][0][i]);
    }
    for(int i = 2; i <= n; i++) {
    	for(int j = 0; j <= m; j++) {
    		for(int k = 0; k <= n; k++)
    			dp[i & 1][j][k] = inf;
    		mn[i & 1][j] = inf;
    	}
    	for(int j = 0; j <= m; j++) {
    		for(int k = 1; k <= n; k++) {
    			if(a[k] >= a[i])
    				dp[i & 1][j][k] = min(dp[i & 1][j][k], dp[(i & 1) ^ 1][j][k] + a[k] - a[i]);
    			if(j && a[k] >= a[i])
    				dp[i & 1][j][k] = min(dp[i & 1][j][k], mn[(i & 1) ^ 1][j - 1] + a[k] - a[i]);
    			mn[i & 1][j] = min(mn[i & 1][j], dp[i & 1][j][k]);
    		}
    	}
    }
    int answer = inf;
    for(int i = 0; i <= m; i++)
    	for(int j = 1; j <= n; j++)
    		answer = min(answer, dp[n & 1][i][j]);
    cout << answer << '\n';
    return 0;
}