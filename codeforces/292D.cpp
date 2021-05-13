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

struct UFDS {
    int n, c, comp;
    vector<int> len, par;
    void init(int x, int y = 1) {
        n = x;
        c = y; comp = n;
        par.resize(n+2);
        len.assign(n+2, 1);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }
    bool join(int a, int b) {
        a = fin(a); b = fin(b);
        if(a==b) return false;
        if(rng() % 2) swap(a, b);
        if(c && len[a] < len[b])
            swap(a, b);
        par[b] = a; comp--;
        if(c) len[a] += len[b];
        return true;
    }
    int sz(int x) { return len[fin(x)]; }
};

const int N = 1e4+2;
UFDS a[N], b[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    a[0].init(n);
    b[m + 1].init(n);
    edges.pb(mp(0, 0));
    for(i=0; i<m; i++) {
        int x,y; cin >> x >> y;
        edges.pb(mp(x, y));
    }
    for(i = 1; i <= m; i++) {
        a[i].init(n);
        for(j = 1; j <= n; j++) {
            a[i].join(j, a[i - 1].fin(j));
        }
        a[i].join(edges[i].first, edges[i].second);
    }
    for(i = m; i; i--) {
        b[i].init(n);
        for(j = 1; j <= n; j++) {
            b[i].join(j, b[i + 1].fin(j));
        }
        b[i].join(edges[i].first, edges[i].second);
    }
    int q; cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--; r++;
        UFDS ans; ans.init(n);
        for(i = 1; i <= n; i++) {
            ans.join(i, a[l].fin(i));
        }
        for(i = 1; i <= n; i++) {
            ans.join(i, b[r].fin(i));
        }
        cout << ans.comp << "\n";
    }
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
