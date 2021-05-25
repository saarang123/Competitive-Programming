#include <bits/stdc++.h>
using namespace std;
#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int inf = 2e9;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for(auto &[x, y] : a) 
    	cin >> x >> y;
    if(n == 2)
    	return cout << min(a[0][0] + a[1][1], a[0][1] + a[1][0]) << '\n', 0;

    auto check = [&] (vector<array<int, 2>> pts) {
    	sort(pts.begin(), pts.end());
    	vector<array<int, 2>> p(n), s(n);
    	for(int i = 0; i < n; i++) {
    		p[i][0] = p[i][1] = pts[i][1];
    		if(i) {
    			p[i][0] = min(p[i][0], p[i - 1][0]);
    			p[i][1] = max(p[i][1], p[i - 1][1]);
    		}
    	}
    	for(int i = n - 1; i >= 0; i--) {
    		s[i][0] = s[i][1] = pts[i][1];
    		if(i < n - 1) {
    			s[i][0] = min(s[i][0], s[i + 1][0]);
    			s[i][1] = max(s[i][1], s[i + 1][1]);
    		}
    	}
    	auto cmin = [&] (int i, int j) {
    		if(i < 0) return s[j][0];
    		if(j > n - 1) return p[i][0];
    		return min(p[i][0], s[j][0]);
    	};
    	auto cmax = [&] (int i, int j) {
    		if(i < 0) return s[j][1];
    		if(j > n - 1) return p[i][1];
    		return max(p[i][1], s[j][1]);
    	};
    	auto find = [&] (int j, int i) {
    		return pts[i][0] - pts[j][0] + cmax(j - 1, i + 1) - cmin(j - 1, i + 1);
    	};
    	int ans = inf, i = 0, j = n - 1;
    	while(j - i > 1) {
    		int t1 = inf, t2 = inf, cur = find(i + 1, j - 1);
    		if(i + 2 <= j - 1)
    			t1 = find(i + 2, j - 1);
    		if(i + 1 <= j - 2)
    			t2 = find(i + 1, j - 2);
    		if(t1 < t2)
    			i++;
    		else
    			j--;
    		ans = min({ans, t1, t2, cur});
    	}
    	return ans;
    };
    int ans = check(a);
    for(auto &[x, y] : a)
    	swap(x, y);
    ans = min(ans, check(a));
    cout << ans << '\n';
    return 0;
}