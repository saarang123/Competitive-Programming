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

const int N = 2e5 + 2;
vector<int> g[N];
vector<int> tin(N), vis(N);
vector<int> st, cycle;
bool found = 0;
void dfs(int v, int p) {
    st.pb(v);
    vis[v] = 1;
    tin[v] = st.size() - 1;
    for(int u : g[v]) if(u != p) {
        if(found) return;
        if(vis[u] == 1) {
            found = true;
            for(int i = tin[u]; i < st.size(); i++) cycle.pb(st[i]);
            return;
        }
        else if(vis[u] == 0)
            dfs(u, v);
    }
    vis[v] = 2;
    st.pop_back();
}

void solve_case() {
    int n; cin >> n;
    found = false;
    st.clear(); cycle.clear();
    for(int i = 0; i <= n; i++) { g[i].clear(); tin[i] = -1; vis[i] = 0;}
    vector<array<int, 2>> edges(n);
    for(int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
        edges[i] = {u, v};
    }
    dfs(1, -1);
    vector<bool> in(n + 1);
    for(int x : cycle) in[x] = true;
    function<int(int v, int p)> fin = [&] (int v, int p) {
        int mx = 1;
        for(int u : g[v]) if(u != p) {
            if(in[u]) continue;
            mx += fin(u, v);
        }
        return mx;
    };
    int ans = 0;
    for(int x : cycle) {
        int sz = fin(x, -1);
        ans += (sz * (sz - 1)) / 2;
        ans += (sz * (n - sz));
    }
    cout << ans << '\n';
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
