#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 2;
int a[N], sz[N], mx[N], par[N], ans;
bool u[N];

void init(int n) {
    for(int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
}

int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }

void join(int a, int b) {
    if(!u[a] || !u[b]) return;
    a = fin(a), b = fin(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    mx[a] += mx[b];
    ans = max(ans, mx[a]);
}

void unite(int v) {
    u[v] = true;
    mx[v] = a[v];
    ans = max(ans, mx[v]);
    join(v, v + 1); join(v, v - 1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    init(n);
    vector<int> f(n), id(n);
    for(int &x : f) cin >> x;
    reverse(f.begin(), f.end());
    for(int i = 0; i < n; i++) {
        id[i] = ans;
        unite(f[i]);
    }
    reverse(id.begin(), id.end());
    for(int x : id) cout << x << '\n';
    return 0;
}
