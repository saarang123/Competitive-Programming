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

const int MXN = 100 * 1000 + 3;
const int LGN = 19;
vector<int> g[MXN];
int nxt[MXN], up[MXN][LGN], dt[MXN], tin[MXN], p[MXN];
int n, m, k;
 
void dfs(int v = 1, int pp = 1) {
	up[v][0] = pp;
	tin[v] = ++tin[0];
	for(int i = 1; i < LGN; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(int u : g[v]) if(u != pp) {
		dt[u] = dt[v] + 1;
		dfs(u, v);
	}
}
 
int kth(int v, int diff) {
	for(int i = 0; i < LGN; i++)
		if(diff >> i & 1)
			v = up[v][i];
	return v;
}
 
int LCA(int u, int v) {
	if(dt[u] > dt[v])
		swap(u, v);
	v = kth(v, dt[v] - dt[u]);
	if(u == v)
		return u;
	for(int i = LGN - 1; i >= 0; i--)
		if(up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

void solve_case() {
    int n, m;
    cin >> n >> m;
}
