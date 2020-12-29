#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, s, k;
    cin >> n >> s >> k;
    vector<ll> a(n + 1), d(n + 1);
    vector<array<ll, 2>> c(n + 1);
    for(int i = 1; i < n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1]; //prefix sums
    vector<ll> p(n + 1);
    for(int i = 1; i <= n; i++) p[i] = p[i - 1] + d[i - 1];
    //cout << "prefix sums: ";
    //for(int i = 1; i <= n; i++) cout << p[i] << ' '; cout << '\n';
    for(int i = 1; i <= n; i++) {
        int id = lower_bound(p.begin(), p.end(), p[i] + k) - p.begin();
        if(id > n || p[id] > p[i] + k) id--;
        //cout << id << ' ';
        c[i][0] += a[id] - a[i];
        c[i][1] = id + 1;
        id = lower_bound(p.begin(), p.end(), p[i] - k) - p.begin();
        c[i][0] += a[i] - a[id];
        if(id) c[i][0] += a[id] - a[id - 1];
        //cout << id << ' ' << c[i][0] << '\n';
    }
    vector<ll> prev(n + 1), dp(n + 1);
    array<int, 2> best;
    ll ans = 0;
    for(int j = 1; j <= s; j++) {
        dp[n] = a[n] - a[n - 1];
        for(int i = n - 1; i; i--) {
            dp[i] = c[i][0] + prev[c[i][1]];
            if(dp[i] > ans) {
                ans = dp[i];
                best = {i, j};
            }
        }
        swap(prev, dp);
    }
    vector<int> shield;
    function<void(int i, int j)> out = [&] (int i, int j) {
        if(j == 0) return;
        shield.push_back(i);
        out(c[i][1], j - 1);
    };
    out(best[0], best[1]);
    //cout << ans << '\n';
    cout << shield.size() << '\n';
    for(int x : shield) cout << x << ' '; cout << '\n';
    return 0;
}
