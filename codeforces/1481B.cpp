#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }


std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a)
        cin >> x;
    auto check = [&] () {
        for(int i = 1; i < n; i++)
            if(a[i] > a[i - 1])
                return i - 1;
        return -1;
    };
    int x = -1;
    for(int f = 0; f < k; f++) {
        x = check();
        if(x == -1)
            return void(cout << -1 << '\n');
        a[x]++;
    }
    cout << x + 1 << '\n';
}
