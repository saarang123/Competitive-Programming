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

const int N = 2e5+2;
vector<int> g[N];
int dt[N], par[N];
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j,x;
    cin >> n >> x;
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }
    int mx = -1;
    function<void(int, int, int)> dfs = [&] (int v, int p, int d) {
        dt[v] = d;
        par[v] = p;
        remax(mx, dt[v]);
        for(int u: g[v]) {
            if(u==p) continue;
            dfs(u, v, d+1);
        }
    };
    dfs(1, -1, 0);
    int ds = (dt[x]-1)/2;
    int ans = (dt[x]/2)*2;
    for(i=0; i<ds; i++) x = par[x];
    mx = -1;
    dfs(x, par[x], 0);
    ans += (mx+1)*2;
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
