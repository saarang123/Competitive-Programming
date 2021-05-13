#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+3;
const int mod = 998244353;
vector<int> a[N];
int cnt[N];

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

ll inv(int n) {
    return binpow(n, mod-2);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    ll n; cin >> n;
    for(i=1; i<=n; i++) {
        int k; cin >> k;
        while(k--) {
            cin >> j;
            a[i].pb(j);
            cnt[j]++;
        }
    }
    ll ans = 0;
    ll in = inv(n);
    for(i=1; i<=n; i++) {
        ll sz = inv(a[i].size());
        for(int x: a[i]) {
            ll y = (cnt[x] * in) % mod;
            ans += ((in * y) % mod * sz) % mod;
            ans %= mod;
        }
    }
    cout << ans << "\n";
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
