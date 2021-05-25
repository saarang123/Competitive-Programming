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
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

const int MXN = 100 * 1000 + 3;
vector<int> g[MXN];
long long dp[MXN][2], l[MXN], r[MXN];
int n;

void init() {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
}

void dfs(int v, int p) {
    dp[v][0] = dp[v][1] = 0;
    for(int u : g[v]) if(u != p) {
        dfs(u, v);
        dp[v][0] += max(abs(l[v] - l[u]) + dp[u][0], abs(l[v] - r[u]) + dp[u][1]);
        dp[v][1] += max(abs(r[v] - l[u]) + dp[u][0], abs(r[v] - r[u]) + dp[u][1]);
    }
}

void solve_case() {
    cin >> n;
    init();
    for(int i = 1; i <= n; i++) 
        cin >> l[i] >> r[i];
    for(int u, v, i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}
