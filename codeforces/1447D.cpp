#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 5002;
int dp[N][N], n, m;
string a, b;

int f(int i, int j) {
    if(i > n || j > m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]) {
        dp[i][j] = 2 + f(i + 1, j + 1);
    }
    remax(dp[i][j], f(i + 1, j) - 1);
    remax(dp[i][j], f(i, j + 1) - 1);
    remax(dp[i][j], 0);
    return dp[i][j];
}

void solve_case() {
    cin >> n >> m >> a >> b;
    a = " " + a; b = " " + b;
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ans = max(ans, f(i, j));
        }
    }
    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
