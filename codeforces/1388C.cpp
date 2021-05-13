#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const int N = 1e5+2;
int a[N], h[N], sz[N], x[N], y[N];
vector<int> g[N];
int sub(int v, int p) {
    sz[v] = a[v];
    for(int u: g[v]) {
        if(u==p) continue;
        sz[v] += sub(u, v);
    }
    return sz[v];
}

bool dfs(int v, int p) {
    int sum = 0;
    for(int u: g[v]) {
        if(u==p) continue;
        sum += x[u];
        if(!dfs(u, v)) return false;
    }
    if(sum > x[v]) return false;
    return true;
}

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,m;
    cin >> n >> m;
    for(i=1; i<=n; i++) {
        sz[i] = 1;
        g[i].clear();
    }
    for(i=1; i<=n; i++) cin >> a[i];
    for(i=1; i<=n; i++) cin >> h[i];
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }
    sub(1, -1);
    for(i=1; i<=n; i++) {
        x[i] = (sz[i]+h[i])/2;
        y[i] = sz[i] - x[i];
        if(x[i]+y[i]!=sz[i] || x[i]-y[i]!=h[i] || x[i]<0 || y[i]<0)
            return void(cout << "NO" << "\n");
    }
    if(dfs(1,-1)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
