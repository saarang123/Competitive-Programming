#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000 * 1000 + 2;
int bit[mxn], n, p;

void upd(int x) {
	for(; x <= n; x += (x & -x))
		bit[x]++;
}

long long qry(int x) {
	long long res = 0;
	for(; x > 0; x -= (x & -x))
		res += bit[x];
	return res;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n;
    vector<long long> a(n), b(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    cin >> p;
    for(int i = 0; i < n; i++) {
    	a[i] -= p;
    	if(i)
    		a[i] += a[i - 1];
    	b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    upd(lower_bound(b.begin(), b.end(), 0LL) - b.begin() + 1);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
    	int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    	ans += qry(id);
    	upd(id);
    }
    cout << ans << '\n';
    return 0;
}