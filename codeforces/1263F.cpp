#include <bits/stdc++.h>
using namespace std;

struct tree {
	int n, leaves;
	vector<vector<int>> cost;
	vector<int> p, id;
	void init(int _leaves) {
		leaves = _leaves;
		cin >> n;
		cost = vector<vector<int>>(leaves, vector<int>(leaves));
		p.resize(n);
		id.resize(leaves);
		for(int i = 1; i < n; i++) cin >> p[i], p[i]--;
		for(int i = 0; i < leaves; i++) cin >> id[i], id[i]--;
		for(int l = 0; l < leaves; l++) {
			vector<int> deg(n);
			for(int x : p) deg[x]++;
			int ans = 0;
			for(int r = l; r < leaves; r++) {
				int v = id[r];
				while(v && deg[v] == 0) {
					v = p[v];
					deg[v]--;
					ans++;
				}
				cost[l][r] = ans;
			}
		}
	}
	int get(int l, int r) { return cost[l][r - 1]; }
} a, b;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    a.init(n); b.init(n);
    vector<int> dp(n + 1);
    for(int i = 0; i < n; i++) {
    	for(int j = i + 1; j <= n; j++)
    		dp[j] = max(dp[j], dp[i] + max(a.get(i, j), b.get(i, j)));
    }
    cout << dp[n] << '\n';
    return 0;
}