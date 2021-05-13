#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define int long long

const int N = 1000 * 1000 + 3;
int par[N], sz[N];
int ans = 0;
bool u[N];

int cnt(int v) { return (v * (v + 1)) / 2; }

void init(int n) {
    for(int i = 0; i <= n + 1; i++) par[i] = i, sz[i] = 1;
}

int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }

void join(int a, int b) {
    if(!u[a] || !u[b]) return;
    a = fin(a); b = fin(b);
    if(a == b) return;
    ans -= cnt(sz[a]);
    ans -= cnt(sz[b]);
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    ans += cnt(sz[a]);
}

void unite(int v) {
    u[v] = 1;
    ans += cnt(sz[v]);
    join(v, v + 1);
    join(v, v - 1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, q;
    cin >> n >> q;
    init(n);
    vector<array<int, 2>> a(n), h(q);
    for(int i = 0; i < n; i++) cin >> a[i][0], a[i][1] = i + 1;
    for(int i = 0; i < q; i++) cin >> h[i][0], h[i][1] = i;
    sort(h.begin(), h.end());
    sort(a.begin(), a.end());
    vector<int> id(q);
    int j = 0;
    for(int i = 0; i < q; i++) {
        while(j < n && a[j][0] <= h[i][0]) {
            unite(a[j][1]);
            j++;
        }
        id[h[i][1]] = ans;
    }
    for(int i = 0; i < q; i++) cout << id[i] << '\n';
    return 0;
}
