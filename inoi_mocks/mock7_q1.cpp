#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int m;
    cin >> m;
    const int h = 10;
    vector<array<bool, 3>> seen(1 << 13);
    while(m--) {
    	int n; cin >> n;
    	vector<array<int, 2>> g(n);
    	vector<bool> leaf(n), left(n), right(n), both(n);
    	for(int i = 0; i < n; i++) {
    		cin >> g[i][0] >> g[i][1];
    		leaf[i] = max(g[i][0], g[i][1]) == 0;
    		g[i][0]--, g[i][1]--;
    		both[i] = (min(g[i][0], g[i][1]) != -1);
    		left[i] = (g[i][0] != -1 && g[i][1] == -1);
    		right[i] = (g[i][1] != -1 && g[i][0] == -1);
    	}
    	function<void(int v, int cnt)> dfs = [&] (int v, int cnt) {
    		if(leaf[v]) {
    			return;
    		}
    		//cout << "dfs: " << v << endl;
    		if(both[v] && leaf[g[v][0]] && leaf[g[v][1]])
    			seen[cnt][2] = true;
    		if(left[v] && leaf[g[v][0]])
    			seen[cnt][0] = true;
    		if(right[v] && leaf[g[v][1]])
    			seen[cnt][1] = true;
    		if(g[v][0] > -1)
    			dfs(g[v][0], cnt * 2 + 1);
    		if(g[v][1] > -1)
    			dfs(g[v][1], cnt * 2 + 2);
    	};
    	dfs(0, 0);
    	if(n == 1)
    		seen[0] = {1, 1, 1};
    }
    int j = 0;
    for(int i = 0; i <= h; i++) {
    	bool sum = true;
    	for(int k = 0; k < (1 << i); k++, j++)
    		sum = sum && seen[j][0] && seen[j][1] && seen[j][2];
    	if(sum)
    		return void(cout << "Almost Complete\n");
    }
    cout << "No\n";
}
