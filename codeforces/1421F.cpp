#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define deb(u) cout << #u << " :: " << u << "\n";
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
const int N = 2e5 + 2;
vector<int> g[N];
int n, a[N], dp[N], c[N], is[N], ans, ok[N];
map<int, int> cnt;
set<int> sz[N];

map<int, int> dfs(int v, int p) {
    map<int, int> st;
    cout << v << " " << p << endl;
    is[v] = 1;
    for(int u : g[v]) {
        if(u == p)
            continue;
        cout << "child : " << u << endl;
        map<int, int> tmp = dfs(u, v);
        if(tmp[a[v]] > 0) sz[v].insert(u);
        if(tmp.size() < st.size()) swap(st, tmp);
        for(auto x : tmp) st[x.first] += x.second;
        is[v] = (is[v] && (dp[u] == g[u].size() - 1));
        dp[v] += sz[u].empty();
    }
    c[v] = ++st[a[v]];
    return st;
}

void solve_case() {
    int i,j;
    cin >> n;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i < n; i++) {
        int v, u; cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }
    cnt = dfs(1, -1);
    //for(i = 1; i <= n; i++) print(i); cout << "\n";
    //for(i = 1; i <= n; i++) cout << dp[i] << " "; cout << "\n";
    //reroot(1, -1);
    int ans = 0;
    for(i = 1; i <= n; i++) ans += is[i];
    for(i = 1; i <= n; i++) cout << is[i] << " "; cout << "\n";
    cout << ans << "\n";

}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
