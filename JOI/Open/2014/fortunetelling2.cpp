#include <bits/stdc++.h>
using namespace std;
const int MXN = 700 * 1000 + 3;
int tree[MXN << 2], a[MXN], b[MXN], t[MXN], oga[MXN], ogb[MXN];
vector<int> coord, q[MXN];
int n, k, sz;

function<int(int, int)> comb = [] (int x, int y) {
	return max(x, y);
};

void update(int v, int tl, int tr, int pos, int x) {
	if(tl == tr)
		tree[v] = comb(tree[v], x);
	else {
		int tm = (tl + tr) >> 1;
		if(pos <= tm)
			update(v << 1, tl, tm, pos, x);
		else
			update(v << 1|1, tm + 1, tr, pos, x);
		tree[v] = comb(tree[v << 1], tree[v << 1|1]);
	}
}

void upd(int pos, int x) {
	update(1, 1, MXN - 2, pos, x);
}

int query(int v, int tl, int tr, int l, int r) {
	if(l > r)
		return 0;
	if(l <= tl && tr <= r)
		return tree[v];
	int tm = (tl + tr) >> 1;
	return comb(query(v << 1, tl, tm, l, min(tm, r)),
				query(v << 1|1, tm + 1, tr, max(tm + 1, l), r));
}

int query(int l, int r) {
	return query(1, 1, MXN - 2, l, r);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
    	cin >> oga[i] >> ogb[i];
    	coord.push_back(oga[i]);
    	coord.push_back(ogb[i]);
    }
    for(int i = 1; i <= k; i++) {
    	cin >> t[i];
    	coord.push_back(t[i]);
    }

    sort(coord.begin(), coord.end());
    coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
    sz = coord.size();
    auto id = [&] (int x) {
    	return upper_bound(coord.begin(), coord.end(), x) - coord.begin();
    };
    for(int i = 1; i <= n; i++) {
    	a[i] = id(oga[i]);
    	b[i] = id(ogb[i]);
    }
    for(int i = 1; i <= k; i++) {
    	t[i] = id(t[i]);
    	upd(t[i], i);
    }

    for(int i = 1; i <= n; i++) {
    	int x = query(min(a[i], b[i]), max(a[i], b[i]) - 1);
    	q[x].push_back(i);
    }
    memset(tree, 0, sizeof tree);
    comb = [&] (int x, int y) {
    	return x + y;
    };
    long long ans = 0;
    for(int x = k; x >= 0; x--) {
    	for(int i : q[x]) {
    		int parity = query(max(a[i], b[i]), sz) & 1;
    		if(x)
    			parity ^= a[i] < b[i];
    		ans += parity ? ogb[i] : oga[i];
    	}
    	upd(t[x], 1);
    }

    cout << ans << '\n';
    return 0;
}