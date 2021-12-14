#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 1010;
int n, m;
int dist[N];
int ed[4 * N][3];
int par[N];

void addEdge(int v, int u, int w) {
	ed[m][0] = v;
	ed[m][1] = u;
	ed[m][2] = w;
	m++;
}

void solve() {
	int k;
	scanf("%d%d", &n, &k);
	m = 0;
	for (int i = 1; i < n; i++) {
		scanf("%d", &par[i]);
		par[i]--;
		addEdge(par[i], i, 1);
		addEdge(i, par[i], 0);
	}
	while(k--) {
		int v, u, l, r;
		scanf("%d%d%d%d", &v, &u, &l, &r);
		v--;u--;
		addEdge(v, u, r);
		addEdge(u, v, -l);
	}
	for (int v = 0; v < n; v++)
		dist[v] = N;
	dist[0] = 0;
	bool ch = true;
	for (int it = 0; ch && it <= n; it++) {
		if (it == n) {
			printf("-1\n");
			return;
		}
		ch = false;
		for (int i = 0; i < m; i++) {
			int v = ed[i][0], u = ed[i][1], w = ed[i][2];
			w += dist[v];
			if (w < 0) {
				printf("-1\n");
				return;
			}
			if (w >= dist[u]) continue;
			dist[u] = w;
			ch = true;
		}
	}
	int cnt = 0;
	for (int i = 1; i < n; i++)
		cnt += dist[i] - dist[par[i]];
	printf("%d\n", cnt);
	for (int i = 1; i < n; i++)
		if (dist[i] > dist[par[i]])
			printf("%d ", i + 1);
	printf("\n");
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}
