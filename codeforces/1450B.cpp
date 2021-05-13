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
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n, k;
    auto dt = [&] (array<int, 2> a, array<int, 2> b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    };
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for(auto &x : a) cin >> x[0] >> x[1];
    for(int i = 0; i < n; i++) {
        bool ok = 1;
        for(int j = 0; j < n; j++)
            ok = ok && (dt(a[i], a[j]) <= k);
        if(ok)
            return void(cout << 1 << '\n');
    }
    cout << -1 << '\n';
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
