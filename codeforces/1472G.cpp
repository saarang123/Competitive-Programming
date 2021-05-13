#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
	#endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

const int N = 2e5 + 3;
const int inf = 1e9;
vector<int> g[N];
vector<int> d, dp;
int n, m;

void init() {
	d.assign(n, inf);
	dp.assign(n, inf);
	for(int i = 0; i < n; i++) {
		g[i].clear();
	}
}

void bfs(int x) {
	d[x] = 0;
	queue<int> q;
	q.push(x);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u : g[v]) {
			if(d[u] == inf) {
				d[u] = d[v] + 1;
				q.push(u);
			}
		}
	}
}

void solve_case() {
    cin >> n >> m;
    init();
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[--u].push_back(--v);
    }
    bfs(0);
    vector<int> order(n);
	iota(all(order), 0);
	sort(all(order), [&] (int x, int y) {
		return d[x] > d[y]; //processing further nodes first
	});
	for(int v : order) {
		dp[v] = d[v];
		for(int u : g[v]) {
			if(d[u] <= d[v]) dp[v] = min(dp[v], d[u]);
			else dp[v] = min(dp[v], dp[u]);
		}
	}
	for(int i = 0; i < n; i++) cout << dp[i] << ' '; cout << '\n';
}
