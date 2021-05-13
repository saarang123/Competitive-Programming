#include <bits/stdc++.h>
#ifndef saarang
#include "factories.h"
#endif
using namespace std;
const int mxn = 500 * 1000 + 3, lgn = 21;
vector<array<int, 2>> g[mxn];
int sz[mxn], par[mxn], dt[mxn], lvl[mxn];
long long d[mxn], ans[mxn], dist[lgn][mxn];
bool cent[mxn];
int n, m, cnt;
 
int dfssz(int v, int p = -1) {
    sz[v] = 1;
    for(auto &[u, w] : g[v]) if(u != p && !cent[u])
        sz[v] += dfssz(u, v);
    return sz[v];
}
 
int fcent(int v, int p = -1) {
    for(auto &[u, w] : g[v]) if(u != p && !cent[u])
        if(sz[u] > cnt / 2)
            return fcent(u, v);
    return v;
}
 
void fdist(int v, int p, int l) {
	for(auto &[u, w] : g[v]) if(u != p && !cent[u]) {
		dist[l][u] = dist[l][v] + w;
		fdist(u, v, l);
	}
}
 
void decompose(int v, int p = -1, int dep = 0) {
    cnt = dfssz(v);
    int centroid = fcent(v);
    par[centroid] = p;
    lvl[centroid] = dep;
    dist[dep][centroid] = 0;
    fdist(centroid, -1, dep);
    cent[centroid] = true;
    for(auto &[u, w] : g[centroid]) if(u != p && !cent[u])
        decompose(u, centroid, dep + 1);
}
 
void upd(int v) {
    for(int p = v; p != -1; p = par[p])
        ans[p] = min(ans[p], dist[lvl[p]][v]);
}
 
long long qry(int v) {
    long long res = ans[n];
    for(int p = v; p != -1; p = par[p])
        res = min(res, ans[p] + dist[lvl[p]][v]);
    return res;
}
 
void fix(int v) {
	for(int p = v; p != -1; p = par[p])
		ans[p] = ans[n];
}
 
void Init(int N, int A[], int B[], int D[]) {
	n = N;
	for(int i = 0; i < n - 1; i++) {
		g[A[i]].push_back({B[i], D[i]});
		g[B[i]].push_back({A[i], D[i]});
	}
	decompose(0, -1, 0);
	for(int i = 0; i <= n; i++)
        ans[i] = 1'000'000'000'000'000'000;
}
 
long long Query(int S, int X[], int T, int Y[]) {
	for(int i = 0; i < T; i++)
		upd(Y[i]);
	long long answer = ans[n];
	for(int i = 0; i < S; i++)
		answer = min(answer, qry(X[i]));
	for(int i = 0; i < T; i++)
		fix(Y[i]);
	return answer;
}
 
#ifdef saarang
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int N, Q;
    cin >> N >> Q;
    int A[N - 1], B[N - 1], D[N - 1];
    for(int i = 0; i < N - 1; i++) 
    	cin >> A[i] >> B[i] >> D[i];
    Init(N, A, B, D);
    while(Q--) {
    	int S, T;
    	cin >> S >> T;
    	int X[S], Y[T];
    	for(int i = 0; i < S; i++)
    		cin >> X[i];
    	for(int i = 0; i < T; i++)
    		cin >> Y[i];
    	cout << Query(S, X, T, Y) << '\n';
    }
    return 0;
}
#endif
