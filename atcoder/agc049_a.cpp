#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int mxn = 103;
bool g[mxn][mxn], f[mxn][mxn];
int n, id;

void dfs(int v) {
	f[v][id] = true;
	for(int i = 0; i < n; i++)
		if(g[v][i] && !f[i][id])
			dfs(i);
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
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < n; j++) {
    		char c; cin >> c;
    		g[i][j] = c - '0';
    	}
    }
    for(id = 0; id < n; id++)
    	dfs(id);
    ld ans = 0;
    for(int i = 0; i < n; i++) {
    	int cnt = 0;
    	for(int j = 0; j < n; j++)
    		cnt += f[i][j];
    	ans += 1.0 / cnt;
    }
    cout << fixed << setprecision(15) << ans << '\n'; 
    return 0;
}