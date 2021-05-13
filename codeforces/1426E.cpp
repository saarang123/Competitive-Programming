#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}
#define int long long
void solve_case() {
    int n, i, j;
    cin >> n;
    int a[3], b[3];
    for(i = 0; i < 3; i++) cin >> a[i];
    for(i = 0; i < 3; i++) cin >> b[i];
    int ans = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    int x = max(0LL, a[0] - b[0] - b[2]) + max(0LL, a[1] - b[0] - b[1]) + max(0LL, a[2] - b[1] - b[2]);
    cout << x << " " << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
