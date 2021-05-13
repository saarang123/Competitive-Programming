#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case() {
    int n, m;
    cin >> n >> m;
    int sum = 0, mx = 1e9;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x; cin >> x;
            cnt += (x < 0);
            sum += abs(x);
            mx = min(mx, abs(x));
        }
    }
    if(cnt & 1) sum -= 2 * mx;
    cout << sum << '\n';
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
