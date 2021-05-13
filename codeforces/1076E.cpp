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

struct BIT {
    int n;
    vector<int> bit;
    void init(int x) {
        n = x;
        bit.resize(n + 2,0);
    }
    void init(vector<int> &a) {
        n = a.size();
        bit.resize(n+2, 0);
        for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1]; //check this
			if(i + (i & -i) <= n)
				bit[i + (i & -i)] += bit[i];
		}
    }
    int qry(int x) {
        x = min(x, n);
        int ans = 0;
        for(; x > 0; x -= (x & -x))
            ans += bit[x];
        return ans;
    }
    void upd(int x, int v) {
        if(x <= 0) return;
        for(; x <= n; x += (x & -x))
            bit[x] += v;
    }
};

const int N = 3e5+2;
vector<int> g[N];
vector<pair<int, int>> query[N];
BIT bit;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,m,i,j;
    cin >> n;
    bit.init(n + 3);
    for(i = 0; i < n - 1; i++) {
        int v, u; cin >> v >> u;
        g[v].pb(u); g[u].pb(v);
    }
    cin >> m;
    while(m--) {
        int v, d, x;
        cin >> v >> d >> x;
        query[v].pb(mp(d, x));
    }
    vector<int> ans(n + 1);
    function<void(int v, int p, int d)> dfs = [&] (int v, int p, int d) {
        for(auto q: query[v]) {
            bit.upd(d, q.second);
            bit.upd(min(n + 1, d + q.first + 1), -q.second);
        }
        ans[v] = bit.qry(d);
        for(int u : g[v]) {
            if(u == p) continue;
            dfs(u, v, d + 1);
        }
        for(auto q: query[v]) {
            bit.upd(d, -q.second);
            bit.upd(min(n + 1, d + q.first + 1), q.second);
        }
    };
    dfs(1, -1, 1);
    for(i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
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
