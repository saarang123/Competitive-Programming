#include <bits/stdc++.h>
using namespace std;

vector<int> find_subset(int l, int r, vector<int> w) {
	using ll = long long;
	vector<array<ll, 2>> a;
	for(int i = 0; i < w.size(); i++)
		a.push_back({w[i], i});
	sort(a.begin(), a.end());
	vector<int> ans;
	int j = 0, n = a.size();
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		while(j < n && sum < l)
			sum += a[j++][0];
		if(l <= sum && sum <= r) {
			for(int k = i; k < j; k++)
				ans.push_back(a[k][1]);
			return ans;
		}
		sum -= a[i][0];
	}
	return ans;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int &x : a)
    	cin >> x;
    vector<int> ans = find_subset(l, r, a);
    for(int x : ans)
    	cout << x << ' ';
    cout << '\n';
    return 0;
}