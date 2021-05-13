#include <bits/stdc++.h>
using namespace std;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(auto &arr : a)
    	for(auto &x : arr)
    		cin >> x;
    int l = -1, r = -1;
    auto check = [&] (int k) {
    	vector<int> mask(1 << m);
    	for(int i = 0; i < n; i++) {
    		int c = 0;
    		for(int j = 0; j < m; j++) {
    			if(a[i][j] >= k)
    				c ^= (1 << j);
    		}
    		mask[c] = i + 1;
    	}
    	for(int i = 0; i < (1 << m); i++)
    		for(int j = 0; j < (1 << m); j++)
    			if(mask[i] && mask[j] && (i | j) == ((1 << m) - 1)) {
    				l = mask[i]; r = mask[j];
    				return true;
    			}
    	return false;
    };
    int mn = 0, mx = 1000 * 1000 * 1002;
    while(mn < mx) {
    	int mid = (mn + mx + 1) >> 1;
    	if(check(mid))
    		mn = mid;
    	else
    		mx = mid - 1;
    }
    check(mn);
    cout << l << ' ' << r << '\n';
    return 0;
}