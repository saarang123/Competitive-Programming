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
    vector<long long> a(n), d;
    for(auto &x : a)
    	cin >> x;
    for(int i = 1; i < n; i++)
    	d.push_back(a[i] - a[i - 1] - 1);
    sort(d.begin(), d.end(), greater<>());
    long long ans = a.back() - a[0] + 1;
    for(int i = 0; i < min(k - 1, (int) d.size()); i++)
    	ans -= d[i];
    cout << ans << '\n';
    return 0;
}