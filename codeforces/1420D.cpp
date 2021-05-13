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

#define int long long
const int mod = 998244353;
const int N = 3e5+2;
int fact[N], inv[N];

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

int inverse(int v) {
    return binpow(v, mod - 2);
}

void init(int n) {
    inv[0] = fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        inv[i] = inverse(fact[i]) % mod;
    }
}

int nCr(int n, int r) {
    if(r > n || n < 0LL || r < 0LL) return 0;
    return (fact[n] * ((inv[r] * inv[n - r]) % mod) % mod);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n, i, j, k;
    cin >> n >> k;
    init(n);
    vector<pair<int, int>> a;
    for(i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        a.pb(mp(l, -1));
        a.pb(mp(r, 1));
    }
    sort(all(a));
    //for(auto x: a) cout << x.first << " " << x.second << "\n"; cout << "\n";
    int tmp = 0, ans = 0;
    for(pair<int, int> x : a) {
        if(x.second == -1) {
            //cout << tmp <<  " " << nCr(tmp, k - 1) << " \n";
            ans += nCr(tmp, k - 1);
            ans = (ans + mod) % mod;
            tmp++;
        }
        else {
            tmp--;
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
