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

void solve_case() {
    int n,i,j;
    cin >> n;
    vector<int> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ans(n, 1e9), f[n + 1];
    for(i = 0; i < n; i++)
        f[a[i]].pb(i);
    for(i = 1; i <= n; i++) {
        int last = -1, got = 1;
        f[i].pb(n);
        for(int x : f[i]) {
            remax(got, x - last);
            last = x;
        }
        if(got <= n) {
            remin(ans[got - 1], i);
        }
    }
    for(i = 0; i < n; i++) {
        if(i) remin(ans[i], ans[i - 1]);
        cout << (ans[i] >= 1e9 ? -1 : ans[i]) << " ";
    }
    cout << "\n";
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
