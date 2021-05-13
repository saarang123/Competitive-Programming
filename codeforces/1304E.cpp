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

struct LCA {
    int n,i,j,t;
    vector<vector<int>> g, par;
    vector<int> dt;
    void init(int x) {
        n = x; t = ceil(log2(n));
        dt.resize(n+2);
        g = vector<vector<int>>(n+2, vector<int>());
        par = vector<vector<int>>(n + 2, vector<int>(t + 2));
    }
    void add(int v, int u) { g[v].pb(u); g[u].pb(v); }
    void build(int v = 1, int p = 1, int d = 0) {
        dt[v] = d; par[v][0] = p;
        for(i=1; i<t; i++) {
            if(par[par[v][i-1]][i-1] != -1) par[v][i] = par[par[v][i-1]][i-1];
        }
        for(int u: g[v]) {
            if(u == p) continue;
            build(u, v, d+1);
        }
    }
    int kth(int a, int diff) {
        for(i=0; i<t; i++) {
            if(diff & (1 << i))
                a = par[a][i];
        }
        return a;
    }
    int lca(int a, int b) {
        if(dt[a] < dt[b]) swap(a, b);
        a = kth(a, dt[a] - dt[b]);
        if(a == b) return a;
        for(i=t; i>=0; i--) {
            if(par[a][i] != par[b][i]) { a = par[a][i]; b = par[b][i]; }
        }
        return par[a][0];
    }
    int dist(int a, int b) { return dt[a] + dt[b] - 2 * dt[lca(a,b)]; }
};

bool check(int d, int k) {
    return (d<=k && (k-d)%2==0);
}

void solve_case() {
    int n,i,j,k,m,q;
    cin >> n;
    LCA tree;
    tree.init(n);
    for(i=0; i<n-1; i++) {
        int v,u; cin >> v >> u;
        tree.add(v, u);
    }
    tree.build();
    cin >> q;
    while(q--) {
        int x,y,a,b;
        cin >> x >> y >> a >> b >> k;
        int d1 = tree.dist(a,b), d2 = tree.dist(a,x) + 1 + tree.dist(b,y), d3 = tree.dist(a,y) + 1 + tree.dist(b,x);
        if(check(d1,k) || check(d2,k) || check(d3,k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
