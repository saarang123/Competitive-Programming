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
void solve_case() {
    int n, m, i;
    cin >> n >> m;
    vector<array<int,2>> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    sort(all(a));
    int mn = 1, mx = 1e9, ans = 1, x = (n + 1) / 2;
    vector<int> c(n);
    while(mn < mx) {
        int mid = (mn + 1 + mx) >> 1;
        int sum = 0, ok = 0;
        for(auto tx : a) sum += tx[0];
        for(i = n - 1; i >= 0 && ok < x; i--) {
            if(a[i][1] >= mid) {
                sum += max(mid - a[i][0], 0LL);
                ok++;
            }
        }
        if(ok == x && sum <= m) mn = mid;
        else mx = mid - 1;
    }
    cout << mn << "\n";
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
