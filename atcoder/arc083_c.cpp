#include <bits/stdc++.h>
using namespace std;
const int mxn = 1003, mxc = 5003;
vector<int> g[mxn];
bitset<mxc> t[mxn];
int dp[mxn], a[mxn], n;

void dfs(int v) {
	if(g[v].empty())
		return dp[v] = 0, void();
	t[v][0] = 1;
	int sum = 0;
	for(int u : g[v]) {
		dfs(u);
		sum += a[u] + dp[u];
		t[v] = (t[v] << a[u]) | (t[v] << dp[u]);
	}
	for(int i = a[v]; i >= 0; i--) {
		if(t[v][i]) {
			dp[v] = sum - i;
			break;
		}
	}
	if(dp[v] >= dp[0]) {
		cout << "IMPOSSIBLE" << '\n';
		exit(0);
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
    cin >> n;
    for(int p, i = 2; i <= n; i++) {
    	cin >> p;
    	g[p].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    memset(dp, 0x5f, sizeof dp);
    dfs(1);
    cout << "POSSIBLE" << '\n';
    return 0;
}