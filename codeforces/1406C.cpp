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

const int N = 1e5+2;
vector<int> g[N];
int sz[N], dp[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i = 1; i <= n; i++) {
        g[i].clear(); sz[i] = 0, dp[i] = 1e9;
    }
    for(i=1; i<n; i++) {
        int v,u; cin >> v >> u;
        g[v].pb(u); g[u].pb(v);
    }
    function<int(int v, int p)> dfs = [&] (int v, int p) {
        sz[v] = 1;
        for(int u: g[v]) {
            if(u == p) continue;
            sz[v] += dfs(u, v);
        }
        return sz[v];
    };
    vector<int> cent;
    function<void(int v, int p)> fcent = [&] (int v, int p) {
        bool centroid = true;
        for(int u: g[v]) {
            if(u == p) continue;
            if(sz[u] > n/2)
                centroid = false;
        }
        if(n - sz[v] > n/2) centroid = false;
        if(centroid) cent.pb(v);
        for(int u: g[v]) {
            if(u == p) continue;
            fcent(u, v);
        }
    };
    dfs(1, -1); fcent(1, -1);
    //for(int u: cent) cout << u << " "; cout << "\n";
    if(n == 2 || cent.size() <= 1) {
        cout << 1 << " " << g[1][0] << "\n";
        cout << g[1][0] << " " << 1 << "\n";
    }
    else {
        int c1 = cent[0], c2 = cent[1];
        int mx = -1;
        for(int u: g[c1]) if(u != c2) mx = u;
        cout << c1 << " " << mx << "\n";
        cout << mx << " " << c2 << "\n";
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
