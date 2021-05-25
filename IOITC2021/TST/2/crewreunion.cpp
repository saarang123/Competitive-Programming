#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<array<int, 2>>> g(n);
    vector<vector<int>> deg(n, vector<int> (k));
    for(int u, v, x, i = 0; i < m; i++) {
    	cin >> u >> v >> x;
    	u--, v--, x--;
    	g[v].push_back({u, x});
    	deg[u][x]++;
    }
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    shuffle(perm.begin(), perm.end(), rng);
    for(int i : perm) {
    	//cout << "here\n";
    	vector<vector<array<int, 2>>> depth(n * n + 4);
    	vector<vector<bool>> vis(n, vector<bool> (k + 1));
    	vector<vector<int>> dist(n, vector<int> (k + 1));
    	vector<int> done(n);
    	queue<array<int, 2>> q;
    	q.push({i, k});
    	vis[i][k] = true;
    	int dt = 0;
    	while(!q.empty()) {
    		auto [v, c] = q.front();
    		dt = max(dt, dist[v][c]);
    		done[v] = true;
    		q.pop();
    		for(auto &[u, w] : g[v]) if(!vis[u][w]) {
    			vis[u][w] = true;
    			dist[u][w] = dist[v][c] + 1;
    			q.push({u, w});
    			if(dist[u][w] <= n * n)
    				depth[dist[u][w]].push_back({u, w});
    		}
    	}
    	bool possible = accumulate(done.begin(), done.end(), 0) == n;
    	if(!possible)
    		continue;
    	// cout << i << ": " << possible << '\n';
    	// for(int j = 1; j <= dt; j++) {
    	// 	cout << "depth: " << j << '\n';
    	// 	for(auto &[v, c] : depth[j])
    	// 		cout << v << ' ' << c << '\n';
    	// }
    	//cout.flush();
    	vector<int> ans;
    	vector<bool> solved(n);
    	for(int j = 1; j <= dt && possible; j++) {
    		//cout << "Doing: " << j << '\n';
    		vector<set<int>> col(k);
    		for(auto &[u, c] : depth[j]) if(!solved[u])
    			col[c].insert(u);
    		for(int x = 0; x < k && possible; x++) if(!col[x].empty()) 
    		for(int y = 0; y < k && possible; y++) if(x != y) {
    			for(int u : col[y])
    				if(deg[u][x] && !col[x].count(u)) {
    					possible = false;
    					break;
    				}
    		}
    		for(int x = 0; x < k && possible; x++) if(!col[x].empty()) {
    			for(int u : col[x])
    				solved[u] = true;
    			ans.push_back(x);
    		}
    	}
    	if(possible && ans.size() <= n * n * n) {
    		reverse(ans.begin(), ans.end());
    		cout << "YES" << '\n';
    		cout << ans.size() << ' ';
    		for(int c : ans)
    			cout << c + 1 << ' ';
    		cout << '\n';
    		return;
    	}
    }
    cout << "NO" << '\n';
}
