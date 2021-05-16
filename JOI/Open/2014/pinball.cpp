#include <bits/stdc++.h>
using namespace std;
const int MXN = 100 * 1000 + 3;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long tree[2][(3 * MXN) << 2];
map<int, long long> compress;
int A[MXN], B[MXN], C[MXN], D[MXN];
int N, M;

void update(int v, int tl, int tr, int pos, long long val, int idx) {
	if(tl == tr)
		return tree[idx][v] = min(tree[idx][v], val), void();
	int tm = (tl + tr) >> 1;
	if(pos <= tm)
		update(v << 1, tl, tm, pos, val, idx);
	else
		update(v << 1|1, tm + 1, tr, pos, val, idx);
	tree[idx][v] = min(tree[idx][v << 1], tree[idx][v << 1|1]);
}

void upd(int pos, long long val, int idx) {
	update(1, 1, 3 * M, pos, val, idx);
}

long long query(int v, int tl, int tr, int l, int r, int idx) {
	if(l > r) return INF;
	if(l <= tl && tr <= r)
		return tree[idx][v];
	int tm = (tl + tr) >> 1;
	return min(query(v << 1, tl, tm, l, min(tm, r), idx),
				query(v << 1|1, tm + 1, tr, max(tm + 1, l), r, idx));
}

long long query(int l, int r, int idx) {
	return query(1, 1, 3 * M, l, r, idx);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> M >> N;
    compress[1] = compress[N] = 0;
    for(int i = 1; i <= M; ++i) {
    	cin >> A[i] >> B[i] >> C[i] >> D[i];
    	compress[A[i]] = compress[B[i]] = compress[C[i]] = 0;
    }
    int t = 0;
    for(auto &[u, v] : compress)
    	v = ++t;

    memset(tree, 0x7f, sizeof tree);
    long long ans = INF;
    upd(compress[1], 0, 0);
    upd(compress[N], 0, 1);
    for(int i = 1; i <= M; i++) {
    	long long prefix = query(compress[A[i]], compress[B[i]], 0);
    	long long suffix = query(compress[A[i]], compress[B[i]], 1);
    	ans = min(ans, prefix + D[i] + suffix);
    	upd(compress[C[i]], prefix + D[i], 0);
    	upd(compress[C[i]], suffix + D[i], 1);
    }
    cout << (ans >= INF ? -1 : ans) << '\n';
    return 0;
}