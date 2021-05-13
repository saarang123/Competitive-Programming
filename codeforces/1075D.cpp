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

const int N = 1e3+3;
int in[N], out[N];
vector<int> g[N];
vector<int> a,b;
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    cin >> n;
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
    }
    int k1,k2;
    cin >> k1;
    while(k1--) {
        cin >> k2;
        a.pb(k2);
        in[k2]++;
    }
    cin >> k2;
    while(k2--) {
        cin >> k1;
        b.pb(k1);
        out[k1]++;
    }
    cout << "B " << b[0] << endl;
    cout.flush();
    int r; cin >> r;
    function<pair<int, int>(int, int, int)> dfs = [&] (int v, int p, int d) {
        if(in[v])
            return mp(d, v);
        pair<int, int>  x = mp(1e9, 1e9);
        for(int u: g[v]) {
            if(u==p) continue;
            x = min(x, dfs(u, v, d+1));
        }
        return x;
    };
    int x = dfs(r, -1, 0).second;
    cout << "A " << x << endl;
    cout.flush();
    int y; cin >> y;
    if(out[y]) cout << "C " << x << endl;
    else cout << "C " << -1 << endl;

    a.clear(); b.clear();
    for(i=1; i<=n; i++) {
        g[i].clear();
        in[i] = out[i] = 0;
    }
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
