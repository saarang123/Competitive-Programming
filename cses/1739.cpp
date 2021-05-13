#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int tree[1004][1004];
 
void update(int r, int c, int val) {
	for (int x = r; x < 1003; x += x & -x) {
		for (int y = c; y < 1003; y += y & -y) {
			tree[x][y] += val;
		}
	}
}
 
int query(int r, int c) {
	int ans = 0;
	for (int x = r; x > 0; x -= x & -x) {
		for (int y = c; y > 0; y -= y & -y) {
			ans += tree[x][y];
		}
	}
	return ans;
}
 
char c[1003][1003];
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	#ifdef saarang
	freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
	freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
	#endif
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (c[i][j] == '*') update(i, j, 1);
		}
	}
 
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y;
			if (c[x][y] == '*') {
				update(x, y, -1);
				c[x][y] = '.';
			} else {
				update(x, y, 1);
				c[x][y] = '*';
			} 
		} else {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2; x1--; y1--;
			cout << query(x2, y2) + query(x1, y1) - query(x1, y2) - query(x2, y1) << '\n';
		}
	}
 
	return 0;
}