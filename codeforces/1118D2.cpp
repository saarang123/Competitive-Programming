#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for(int &x : a) cin >> x, sum += x;
    if(sum < m) return void(cout << -1 << '\n');
    sort(all(a)); reverse(all(a));
    auto check = [&] (int k) {
        int t = 0;
        for(int i = 0; i < n; i++) t += max(0LL, a[i] - i / k);
        return (t >= m);
    };
    int ans = n, mn = 1, mx = n;
    while(mn < mx) {
        int mid = (mn + mx) >> 1;
        if(check(mid)) mx = mid, ans = mid;
        else mn = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    solve_case();
    return 0;
}
