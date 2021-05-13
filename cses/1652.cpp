#include <bits/stdc++.h>
using namespace std;
const int mxn = 1003;
int a[mxn][mxn], n, q;
 
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= n; j++) {
    		char c; cin >> c;
    		a[i][j] = (c == '*');
    	}
    for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= n; j++)
    		a[i][j] = a[i - 1][j] + a[i][j - 1] + a[i][j] - a[i - 1][j - 1];
    auto query = [&] (int x1, int y1, int x2, int y2) {
    	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
    };
    
    while(q--) {
    	int x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	cout << query(x1, y1, x2, y2) << '\n';
    }
    return 0;
}