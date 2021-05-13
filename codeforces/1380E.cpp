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
    vector<int> b(n);
    vector<set<int>> a(m);
    for(int x, i = 0; i < n; i++) {
    	cin >> x; x--;
    	b[i] = x;
    	a[x].insert(i);
    }
    int ans = 0;
    for(int i = 0; i < m; i++) {
    	for(int x : a[i])
    		if(a[i].count(x - 1))
    			ans++;
    }
    cout << n - 1 - ans << '\n';
    for(int _ = 1; _ < m; _++) {
    	int l, r;
    	cin >> l >> r;
    	l--, r--;
    	if(a[l].size() < a[r].size()) swap(a[l], a[r]);
    	for(int x : a[r]) {
    		if(a[l].count(x - 1)) ans++;
    		if(a[l].count(x + 1)) ans++;
    	}
    	for(int x : a[r]) a[l].insert(x);
    	a[r].clear();
    	cout << n - 1 - ans << '\n';
    }
    return 0;
}