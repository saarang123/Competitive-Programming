#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
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

const int N = 3e5 + 3;
vector<int> g[2][N];
vector<array<int, 2>> dp;
set<int> on, off;
void init(int n) {
    for(int j = 0; j < 2; j++)
        for(int i = 0; i <= n; i++)
            g[j][i].clear();
    dp.clear();
    array<int, 2> base = {-1, -1};
    dp.assign(n + 2, base);
}

void dfs(int v, int c) {
    if(dp[v][c] != -1) return;
    dp[v][c] = 1;
    off.insert(v);
    if(c == 0) on.insert(v);
    for(int u : g[c][v]) {
        dfs(u, c ^ 1);
    }
}

void solve_case() {
    int n; cin >> n;
    init(n + 1);
    for(int i = 1; i <= n; i++) {
        char c; cin >> c;
        if(c == 'L') {
            g[0][i].push_back(i - 1);
            g[1][i - 1].push_back(i);
        } else {
            g[0][i - 1].push_back(i);
            g[1][i].push_back(i - 1);
        }
    }
    vector<int> ans(n + 1);
    for(int i = 0; i <= n; i++) if(dp[i][0] == -1) {
        on.clear(); off.clear();
        dfs(i, 0);
        for(int v : on)
            ans[v] = off.size();
    }
    for(int v : ans) cout << v << ' ';
    cout << '\n';
}
