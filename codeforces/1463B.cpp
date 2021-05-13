#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case() {
    int n; cin >> n;
    vector<int> a(n);
    int mx = 0, sum = 0;
    for(int &x : a) cin >> x, mx = max(mx, x), sum += x;
    vector<int> b = a;
    int x = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2) b[i] = 1;
        x += abs(b[i] - a[i]);
    }
    if(2 * x <= sum) {
        for(int c : b) cout << c << ' '; cout << '\n';
        return;
    }
    b = a; x = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) b[i] = 1;
        x += abs(b[i] - a[i]);
    }
    if(2 * x <= sum) {
        for(int c : b) cout << c << ' '; cout << '\n';
        return;
    }
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
