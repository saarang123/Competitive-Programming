#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x % m]++;
    }
    int ans = (a[0] > 0);
    for(int i = 1; i <= (m - 1) / 2; i++) {
        if(a[i] == 0 || a[m - i] == 0) {
            ans += max(a[i], a[m - i]);
            continue;
        }
        ans++;
        if(a[i] != a[m - i]) {
            ans += max(a[m - i], a[i]) - min(a[i], a[m - i]) - 1;
        }
    }
    if(m % 2 == 0)
        ans += (a[m / 2] > 0);
    cout << ans << '\n';
}
