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
    int n,i,j,k;
    cin >> n >> k;
    vector<int> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    if(a.back() > k)
        return void(cout << 0 << "\n");
    int ans = 0;
    for(i = 1; i < n; i++) {
        int x = (k - a[i])/a[0];
        ans += x;
        a[i] += x * a[0];
    }
    sort(all(a));
    int x = max((k - a[0])/a[1], 0LL);
    ans += x;
    cout << ans << "\n";
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
