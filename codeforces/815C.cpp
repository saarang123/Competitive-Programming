#include <bits/stdc++.h>
using namespace std;
const int mxn = 5003;
const long long inf = 1e15;
vector<int> g[mxn];
long long dp[mxn][mxn][2], tmp[mxn][2];
int a[mxn], c[mxn], sz[mxn], b, n;

void dfs(int v) {
	dp[v][0][0] = 0;
	dp[v][0][1] = inf;
	dp[v][1][0] = a[v];
	dp[v][1][1] = a[v] - c[v];
	sz[v] = 1;
	for(int u : g[v]) {
		dfs(u);
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < 2; j++)
				tmp[i][j] = dp[v][i][j];
		for(int i = 0; i <= sz[v]; i++)
			for(int j = 0; j <= sz[u]; j++) {
				dp[v][i + j][0] = min(dp[v][i + j][0], tmp[i][0] + dp[u][j][0]);
				dp[v][i + j][1] = min(dp[v][i + j][1], tmp[i][1] + min(dp[u][j][0], dp[u][j][1]));
			}
		sz[v] += sz[u];
	}
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> b >> a[1] >> c[1];
    for(int x, i = 2; i <= n; i++) {
    	cin >> a[i] >> c[i] >> x;
    	g[x].push_back(i);
    }
    memset(dp, 0x7f, sizeof dp);
    dfs(1);
    for(int i = n; i >= 0; i--)
    	if(min(dp[1][i][0], dp[1][i][1]) <= b)
    		return cout << i << '\n', 0;
    return 0;
}