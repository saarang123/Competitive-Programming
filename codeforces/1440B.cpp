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
    int n, k;
    cin >> n >> k;
    vector<int> a(n * k);
    for(int i = 0; i < n * k; i++) cin >> a[i];
    int ans = 0;
    reverse(all(a));
    int c = 0;
    for(int i = n/2 ; i < n * k; i += 1 + n / 2) {
        ans += a[i];
        c++;
        if(c == k) break;
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
