#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200 * 1000 + 3;
int n, q, a[mxn], d[mxn];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	d[i] = max(d[i - 1] + a[i - 1] - a[i], 0LL);
    }
    for(int i = 1; i <= n; i++)
    	cout << d[i] << ' ';
    cout << '\n';
    while(q--) {
    	int l, r;
    	cin >> l >> r;
    	cout << d[r] - d[l] - (d[l - 1] * (r - l + 1)) << '\n';
    }
    return 0;
}