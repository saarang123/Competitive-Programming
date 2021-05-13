#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define int long long
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
template<class T>
T fexpo(T a, long long b) {
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve_case() {
    int n, b;
    cin >> n >> b;
    int m = b;
    map<int, int> cnt;
    for(int i = 2; i * i <= m; i++) {
        if(m % i) continue;
        while(m % i == 0) {
            cnt[i]++;
            m /= i;
        }
    }
    if(m > 1) cnt[m]++;
    int ans = 1e18;
    for(auto tx : cnt) {
        int f = tx.first, g = tx.second;
        //cout << f << ' ' << g << '\n';
        int c = 0, x = f;
        while(x <= n) {
            c += (n / x);
            if(x > n / f) break;
            x *= f;
        }
        int t = c / g;
        ans = min(ans, t);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcases = 1;
    //cin >> testcases;
    while(testcases--) {
        solve_case();
    }
}
