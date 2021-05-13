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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    auto check = [&] (int m) {
    	vector<int> p(n + 1);
    	for(int i = 1; i <= n; i++)
    		p[i] = p[i - 1] + (a[i] >= m ? 1 : -1);
    	int low = n;
    	for(int i = 1; i <= n; i++) {
    		if(i - k >= 0)
    			low = min(low, p[i - k]);
    		if(p[i] - low > 0)
    			return true;
    	}
    	return false;
    };
    int mn = 1, mx = n;
    while(mn < mx) {
    	int mid = (mn + mx + 1) >> 1;
    	if(check(mid))
    		mn = mid;
    	else
    		mx = mid - 1;
    }
    cout << mn << '\n';
    return 0;
}