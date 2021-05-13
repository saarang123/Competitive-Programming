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

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n;
    ld k;
    cin >> n >> k;
    vector<ld> a(n);
    for(ld &x : a) cin >> x;
    int ans = 0;
    ld sum = a[0], f = (ld) k / 100.0;
    for(int i = 1; i < n; i++) {
        ld r = (ld) a[i] / sum;
        if(r > f) {
            ld add = ceil((100.0 * a[i] - k * sum) / k);
            ans += add; sum += add;
        }
        sum += a[i];
    }
    cout << ans << '\n';
}
