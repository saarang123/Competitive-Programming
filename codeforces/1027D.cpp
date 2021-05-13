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

const int N = 2e5 + 2;
int a[N], c[N], vis[N];
vector<int> g[N];
vector<vector<int>> cycles;
vector<int> path;

void dfs(int v) {
    vis[v] = 1;
    path.pb(v);
    int to = a[v];
    if(vis[to] == 1) {
        vector<int> tmp;
        int id = path.size() - 1;
        while(path[id] != to)
            tmp.pb(path[id--]);
        tmp.pb(to);
        cycles.pb(tmp);
    }
    else if(vis[to] == 0) {
        dfs(to);
    }
    vis[v]++;
    path.pop_back();
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> c[i];
    for(i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(i=1; i<=n; i++) {
        if(!vis[i])
            dfs(i);
    }
    int ans = 0;
    for(auto v: cycles) {
        int x = 1e9;
        for(int u: v)
            remin(x, c[u]);
        ans += x;
    }
    cout << ans << "\n";
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
