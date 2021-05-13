#include <bits/stdc++.h>
using namespace std;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m; cin >> n >> m;
    vector<array<int, 2>> a(n);
    for(auto &in : a) cin >> in[1] >> in[0];
    vector<int> c(m);
    for(int &x : c) cin >> x;
    int ans = 0;
    sort(a.begin(), a.end(), greater<>());
    sort(c.begin(), c.end());
    for(int i = 0; i < n && ans < m; i++) {
        int sz = a[i][1];
        if(c[m - 1 - ans] >= sz)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
