#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e12;
const vector<array<int, 2>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 2, vector<int> (m + 2));
    vector<vector<int>> dt(n + 2, vector<int> (m + 2, inf));
    priority_queue<array<int, 3>> q;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
    		char c; cin >> c;
    		g[i][j] = (c != '.');
    		if(c == '*') {
    			q.push({0, i, j});
    			dt[i][j] = 0;
    		}
    	}
    }
    auto check = [&] (int x, int y) {
    	return x < 1 || y < 1 || x > n || y > m;
    };
    while(!q.empty()) {
    	int x = q.top()[1], y = q.top()[2]; q.pop();
    	for(auto tx : dir) {
    		int dx = tx[0], dy = tx[1];
    		if(check(x + dx, y + dy) || g[x + dx][y + dy]) continue;
    		if(dt[x][y] + 1 < dt[x + dx][y + dy]) {
    			dt[x + dx][y + dy] = dt[x][y] + 1;
    			q.push({-dt[x + dx][y + dy], x + dx, y + dy});
    		}
    	}
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++)
    	if(g[i][j] == 0) ans += (dt[i][j] <= k);
    cout << ans << '\n';
    return 0;
}