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

#define int long long
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,k;
    cin >> n >> k;
    int a[n+2];
    for(i=1; i<=n; i++) cin >> a[i];
    int mx = -1e10;
    for(i=1; i<=n; i++) remax(mx, a[i]);
    for(i=1; i<=n; i++) a[i] = mx-a[i];
    --k;
    mx = -1e18;
    for(i=1; i<=n; i++) remax(mx, a[i]);
    for(i=1; i<=n; i++) {
        if(k%2==1)
            a[i] = mx-a[i];
    }
    for(i=1; i<=n; i++) cout << a[i] << " \n"[i==n];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
