#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_case() {
    ll p, q;
    cin >> p >> q;
    map<int, int> cnt;
    ll t = q;
    for(ll i = 2; i * i <= t; i++) {
        if(t % i) continue;
        while(t % i == 0) {
            cnt[i]++;
            t /= i;
        }
    }
    if(t > 1) cnt[t]++;
    ll ans = 1;
    for(auto x : cnt) {
        ll id = x.first, mn = x.second, c = p, nm = 0;
        while(c % id == 0) {
            nm++;
            c /= id;
        }
        nm = min(nm, mn - 1);
        for(int i = 0; i < nm; i++) c *= id;
        ans = max(ans, c);
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
