#include <bits/stdc++.h>
using namespace std;

vector<int> fix(int n, vector<int> &a) {
	vector<int> dt(n + 1);
	vector<int> mn(26, a[1]), vis(26);
	dt[1] = 1;
	vis[a[1]] = true;
	for(int i = 2; i <= n; i++) {
		dt[i] = dt[i - 1];
		if(mn[a[i]] < a[i]) dt[i]++;
		else if(!vis[a[i]]) dt[i]++;
		for(int j = 0; j < 26; j++) {
			mn[j] = min(mn[j], a[i]);
		}
		vis[a[i]] = true;
		mn[a[i]] = a[i];
	}
	return dt;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
    	char c; cin >> c;
    	a[i] = c - 'A';
    }
    vector<int> da = fix(n, a);
    reverse(a.begin() + 1, a.end());
    vector<int> db = fix(n, a);
    reverse(db.begin() + 1, db.end());
    db.push_back(0);
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	cout << da[l - 1] + db[r + 1] << '\n';
    }
    return 0;
}