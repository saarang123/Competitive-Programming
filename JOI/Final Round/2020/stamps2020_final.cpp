#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 207;
const int inf = 1e18;
int dp[N][N][2][N]; //no (l, r), side, stamps
int x[N], t[N];
int n, m;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    	cin >> x[i];
    x[n + 1] = m;
    for(int i = 1; i <= n; i++)
    	cin >> t[i];
    for(int i = 0; i <= n + 2; i++)
    	for(int j = 0; j <= n + 2; j++)
    		for(int k = 0; k < 2; k++)
    			for(int l = 0; l <= n + 2; l++)
    				dp[i][j][k][l] = inf;
    dp[0][n + 1][0][0] = dp[0][n + 1][1][0] = 0;
    for(int i = 0; i < n; i++) {
    	for(int j = n + 1; j > i + 1; j--) {
    		for(int k = 0; k <= n; k++) {
    			int time = min(dp[i][j][0][k] + (x[i + 1] - x[i]), dp[i][j][1][k] + (m - x[j] + x[i + 1]));  //include i
    			dp[i + 1][j][0][k + (time <= t[i + 1])] = min(dp[i + 1][j][0][k + (time <= t[i + 1])], time);
    			time = min(dp[i][j][0][k] + (m - x[j - 1] + x[i]), dp[i][j][1][k] + (x[j] - x[j - 1]));
    			dp[i][j - 1][1][k + (time <= t[j - 1])] = min(dp[i][j - 1][1][k + (time <= t[j - 1])], time); //include j
    		}
    	}
    }
    int ans = 0;
    for(int i = 0; i <= n + 1; i++)
    	for(int j = 0; j <= n + 1; j++)
    		for(int k = 0; k < 2; k++)
    			for(int l = 0; l <= n; l++)
    				if(dp[i][j][k][l] != inf)
    					ans = max(ans, l);
    cout << ans << '\n';
    return 0;
}