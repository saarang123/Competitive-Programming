#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5+2;
ll a[N], pref[N];
void solve_case() {
    // :pray: :fishy: :orz:
    ll n,h;
    cin >> h >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) {
        pref[i] = a[i] + pref[i-1];
        if(h+pref[i]<=0)
            return void(cout << i << "\n");
    }
    if(pref[n]>=0) return void(cout << -1 << "\n");
    ll ans = 1e18;
    for(int i=1; i<=n; i++) {
        ll tmp = ceil(double(-h-pref[i])/pref[n]);
        remin(ans, i + tmp*n);
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
