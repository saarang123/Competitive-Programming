#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n + 2, vector<bool>(m + 2));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char c; cin >> c;
            if(c == '1') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    vector<array<int, 6>> pts;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(a[i][j]) {
                pts.pb({i, j, i + 1, j, i + 1, j + 1});
                //cout << i << ' ' << j << '\n';
                a[i + 1][j] = !a[i + 1][j];
                a[i + 1][j + 1] = !a[i + 1][j + 1];
            }
        }
        if(a[i][m]) {
            if(a[i + 1][m]) {
                pts.pb({i, m, i + 1, m, i + 1, m - 1});
                a[i + 1][m] = 0;
                a[i + 1][m - 1] = !a[i + 1][m - 1];
            }
            else {
                pts.pb({i, m, i + 1, m, i, m - 1});
                pts.pb({i, m - 1, i + 1, m - 1, i + 1, m});
                a[i + 1][m - 1] = !a[i + 1][m - 1];
            }
        }
    }
    for(int i = 1; i < m; i++) {
        if(a[n][i]) {
            pts.pb({n, i, n - 1, i, n - 1, i + 1});
            pts.pb({n, i + 1, n - 1, i, n - 1, i + 1});
            a[n][i] = !a[n][i];
            a[n][i + 1] = !a[n][i + 1];
        }
    }
    if(a[n][m]) {
        pts.pb({n, m, n - 1, m, n, m - 1});
        pts.pb({n, m - 1, n - 1, m - 1, n, m});
        pts.pb({n, m, n - 1, m - 1, n - 1, m});
    }
    cout << pts.size() << '\n';
    for(auto tx : pts) {
        for(int x : tx) cout << x << ' '; cout << '\n';
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
