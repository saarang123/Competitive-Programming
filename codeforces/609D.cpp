#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, s;
vector<array<int, 2>> ans;
vector<int> a, b;
vector<int> t, c;

bool check(int day) {
	ans.clear();
	int mnp = 0, mnd = 0;
	for(int i = 0; i < day; i++) {
		if(a[i] < a[mnd])
			mnd = i;
		if(b[i] < b[mnp])
			mnp = i;
	}
	vector<array<int, 2>> costs;
	for(int i = 0; i < m; i++) {
		if(t[i] == 1)
			costs.push_back({c[i] * a[mnd], i});
		else
			costs.push_back({c[i] * b[mnp], i});
	}
	sort(costs.begin(), costs.end());
	int sum = 0;
	for(int i = 0; i < k; i++) {
		if(sum + costs[i][0] > s)
			return false;
		sum += costs[i][0];
		ans.push_back({costs[i][1] + 1, (t[costs[i][1]] == 1 ? mnd + 1 : mnp + 1)});
	}
	return true;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> k >> s;
    a.resize(n); b.resize(n);
    t.resize(m); c.resize(m);
    for(int &x : a)
    	cin >> x;
    for(int &x : b)
    	cin >> x;
    for(int i = 0; i < m; i++)
    	cin >> t[i] >> c[i];
    if(!check(n))
    	return cout << -1 << '\n', 0;
    int mn = 1, mx = n;
    while(mn < mx) {
    	int mid = (mn + mx) >> 1;
    	if(check(mid))
    		mx = mid;
    	else
    		mn = mid + 1;
    }
    check(mn);
    cout << mn << '\n';
    for(auto &[id, day] : ans)
    	cout << id << ' ' << day << '\n';
    return 0;
}