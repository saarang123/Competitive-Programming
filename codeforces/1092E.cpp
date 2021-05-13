#include <bits/stdc++.h>
//#include "dreaming.h"
using namespace std;
//IOI13 dreaming xD

const int N = 1e5 + 2;
vector<array<int, 2>> g[N];
bool vis[N];
array<int, 2> par[N];
vector<array<int, 2>> cost;

array<int, 2> dfs(int v, int p, int d) {
    vis[v] = true;
    par[v] = {p, d};
    array<int, 2> ret = {d, v};
    for(auto tx : g[v]) {
        int u = tx[0], w = tx[1];
        if(u == p) continue;
        ret = max(ret, dfs(u, v, d + w));
    }
    return ret;
}

int travelTime(int N,int M,int L, int A[],int B[],int T[]) {
    for(int i = 0; i < M; i++) {
        g[A[i]].push_back({B[i], T[i]});
        g[B[i]].push_back({A[i], T[i]});
    }
    for(int i = 0; i < N; i++) {
        if(vis[i]) continue;
        array<int, 2> y = dfs(i, -1, 0);
        array<int, 2> d = dfs(y[1], -1, 0);
        array<int, 2> v = {d[1], d[0]};  //node, diameter
        array<int, 4> ans = {d[0], d[0], 0, d[1]}; //max of 2 sides, first side, other side, node
        while(v[0] != -1) {
            array<int, 2> x = {v[0], par[v[0]][1]};
            ans = min(ans, {max(d[0] - x[1], x[1]) , d[0] - x[1], x[1], x[0]}); //min max of 2sides
            v = par[v[0]];
        }
        cost.push_back({ans[0], ans[3]});
    }
    sort(cost.begin(), cost.end());
    reverse(cost.begin(), cost.end());
    vector<array<int, 2>> edges;
    for(int i = 1; i < cost.size(); i++) {
        g[cost[0][1]].push_back({cost[i][1], L});
        g[cost[i][1]].push_back({cost[0][1], L});
        edges.push_back({cost[0][1], cost[i][1]});
    }
    array<int, 2> x = dfs(1, -1, 0);
    int answer = dfs(x[1], -1, 0)[0];
    cout << answer << '\n';
    for(auto tx : edges) cout << tx[0] + 1 << ' ' << tx[1] + 1 << '\n';
    return answer;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    //freopen("sample.in", "r", stdin);
    int n, m, l = 1;
    cin >> n >> m;
    int a[m], b[m], t[m];
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i], t[i] = 1;
    for(int i = 0; i < m; i++) a[i]--, b[i]--;
    int answer = travelTime(n, m, l, a, b, t);
    //cout << answer << '\n';
    return 0;
}
