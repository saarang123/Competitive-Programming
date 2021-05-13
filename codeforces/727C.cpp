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
    auto qry = [&] (int x, int y) {
    	cout << "? " << x << ' ' << y << endl;
    	int k; cin >> k;
    	return k;
    };
    int n; cin >> n;
    vector<int> p(n), a(n);
    for(int i = 1; i < n; i++)
    	p[i] = qry(1, i + 1);
    int x = qry(2, 3);
    a[2] = (p[2] - p[1] + x) / 2;
    a[1] = (p[1] - p[2] + x) / 2;
    a[0] = p[1] - a[1];
    for(int i = 3; i < n; i++)
    	a[i] = p[i] - a[0];
    cout << "! ";
    for(int x : a)
    	cout << x << ' ';
    cout << '\n';
    return 0;
}