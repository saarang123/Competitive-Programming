#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
#define int long long
void solve_case() {
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int cnt[2] = {0, 0};
    for(auto c : s) cnt[c - '0']++;
    int ans = 1e9;
    for(int i = 0; i <= n; i++) {
        int tmp = abs(cnt[1] - i) * h + (i * c1) + ((n - i) * c0);
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
