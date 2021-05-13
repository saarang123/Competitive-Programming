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

#define int long long
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m,k;
    cin >> n >> m >> k;
    vector<pair<int, pair<int , int>>> g[n + 1];
    vector<int> dt(n + 1, 1e18), ans, last(n + 1, -1);
    for(i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        g[v].pb(mp(u, mp(w, i + 1)));
        g[u].pb(mp(v, mp(w, i + 1)));
    }
    set<pair<int, int>> q;
    dt[1] = 0;
    q.insert(mp(0, 1));
    int cnt = 0;
    while(!q.empty() && cnt < k) {
        auto x = *q.begin(); q.erase(q.begin());
        int w = x.first, v = x.second;
        if(last[v] != -1) {
            ans.pb(last[v]);
            cnt++;
        }
        for(auto y: g[v]) {
            int u = y.first, w = y.second.first, id = y.second.second;
            if(dt[u] > dt[v] + w) {
                q.erase(mp(dt[u], u));
                dt[u] = dt[v] + w;
                last[u] = id;
                q.insert(mp(dt[u], u));
            }
        }
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << " "; cout << "\n";
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
