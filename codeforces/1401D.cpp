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
const int N = 1e5 + 2;
const int mod = 1e9 + 7;
vector<int> g[N], cnt;
int sz[N],n;

int dfs(int v, int p) {
    sz[v] = 1;
    for(int u: g[v]) {
        if(u == p)
            continue;
        sz[v] += dfs(u, v);
    }
    return sz[v];
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j,m;
    cin >> n;
    for(i=1; i<=n; i++) {
        g[i].clear();
        sz[i] = 0;
    }
    cnt.clear();
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        g[v].pb(u); g[u].pb(v);
    }
    cin >> m;
    vector<int> w;
    while(m--) {
        int x; cin >> x;
        w.pb(x);
    }
    while(w.size() < n-1)
        w.pb(1);
    dfs(1, -1);
    for(i=1; i<n; i++) {
        cnt.pb(sz[i+1] * (n - sz[i+1]));
    }
    sort(all(cnt), greater<int>());
    assert(cnt.size() == n-1);
    int ans = 0;
    if(w.size() == n-1) {
        sort(all(w), greater<int>());
        for(i=0; i<n-1; i++) {
            ans += (w[i] * cnt[i]) % mod;
            ans %= mod;
        }
    }
    else {
        sort(all(w));
        while(w.size() > n-1) {
            int tmp = w.back();
            w.pop_back();
            w.back() *= tmp;
            w.back() %= mod;
        }
        reverse(all(w));
        for(i=0; i<n-1; i++) {
            ans += (w[i] * cnt[i]) % mod;
            ans %= mod;
        }
    }
    cout << ans << "\n";
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
