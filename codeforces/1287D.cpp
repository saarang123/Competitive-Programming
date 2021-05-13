#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define print(a) for(auto u: a) std::cout << u << " "; std::cout << "\n";
#define pb push_back

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e3+2;
std::vector<int> a(N), sz(N), c(N);
std::vector<int> g[N];

int sub(int v) {
    sz[v] = 1;
    for(int u: g[v]) {
        sz[v] += sub(u);
    }
    return sz[v];
}

void dfs(int v, std::vector<int> tmp) {
    int lim = c[v];
    int xs = tmp.size();
    if(xs <= lim ){
        std::cout << "NO" << std::endl;
        exit(0);
    }
    a[v] = tmp[lim];
    int id = 0;
    for(int u: g[v]) {
        std::vector<int> nxt;
        for(int i=0; i<sz[u]; i++) {
            while(a[v] == tmp[id]) id++;
            nxt.pb(tmp[id]);
            id++;
        }
        dfs(u, nxt);
    }
}

void solve_case() {
    // :pray: :fishy: :orz:
    int n; std::cin >> n;
    int root = -1;
    std::vector<int> nused;
    for(int i=1; i<=n; i++)
    {
        int p;
        std::cin >> p >> c[i];
        if(p==0) root = i;
        else g[p].pb(i);
        nused.pb(i);
    }
    sub(root);
    dfs(root, nused);
    std::cout << "YES" << "\n";
    for(int i=1; i<=n; i++) std::cout << a[i] << " \n"[i==n];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
