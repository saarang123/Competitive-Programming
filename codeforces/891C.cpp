#include <bits/stdc++.h>
using namespace std;
const int mxn = 500 * 1000 + 2;
int sz[mxn], par[mxn];
vector<int> ed[mxn];
map<int, vector<int>> queries[mxn];
stack<array<int, 2>> rollback;

int fin(int v) {
    while(par[v] != v) 
        v = par[v];
    return v;
}

bool join(int a, int b) {
    a = fin(a); b = fin(b);
    if(a == b) {
        rollback.push({-1, -1});
        return false;
    }
    if(sz[a] > sz[b]) swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
    rollback.push({a, b});
    return true;
}

void undo() {
    auto [a, b] = rollback.top();
    rollback.pop();
    if(a < 0) 
        return;
    par[a] = a;
    sz[b] -= sz[a];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i], --v[i];
        ed[w[i]].push_back(i);
    }
    int q; cin >> q;
    vector<bool> o(q, true);
    for(int i = 0; i < q; i++) {
        int k; cin >> k;
        while(k--) {
            int x; cin >> x; x--;
            queries[w[x]][i].push_back(x);
        }
    }
    for(int i = 0; i < n; i++) {
        par[i] = i; sz[i] = 1;
    }
    for(int i = 1; i < mxn; i++) {
        for(auto &[id, nodes] : queries[i]) {
            for(int node : nodes) 
                if(!join(u[node], v[node]))
                    o[id] = false;
            for(int k : nodes)
                undo();
        }
        for(int id : ed[i])
            join(u[id], v[id]);
    }
    for(int i = 0; i < q; i++)
        cout << (o[i] ? "YES" : "NO") << '\n';
    return 0;
}