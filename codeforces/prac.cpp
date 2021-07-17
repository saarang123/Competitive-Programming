#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
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

const int MXN = 200 * 1000 + 3;
vector<int> g[MXN];
int dp[MXN], a[MXN], t[MXN];
bool vis[MXN];
int n, m;

int dfs(int v, int p) {
    if(vis[v])
        return 0;
    dp[v] = 0;
    vis[v] = true;
    int sum = a[v];
    for(int u : g[v]) if(u != p) {
        sum += dfs(u, v);
    }
    dp[v] = t[v] - sum;
    return dp[v];
}

void solve_case() {
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        dp[i] = a[i] = t[i] = 0;
        vis[i] = false;
        g[i].clear();
    }
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1; i <= n; i++) 
        cin >> t[i];

    for(int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    // for(int i = 1; i <= n; i++) 
    //     cout << dp[i] << ' ';
    // cout << '\n';
    cout << (dp[1] ? "NO" : "YES") << '\n';
}
