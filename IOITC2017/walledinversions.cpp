#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3, block = 320;
int bit[mxn], a[mxn], n, q;
long long ans = 0;

void upd(int x, int v = 1) {
	for(; x <= n; x += (x & -x))
		bit[x] += v;
}

int qry(int x) {
	int res = 0;
	for(; x > 0; x -= (x & -x))
		res += bit[x];
	return res;
}

int qry(int l, int r) { return qry(r) - qry(l - 1); }

void add(int x, bool side) {
	upd(a[x]);
	if(side)
		ans += qry(a[x] + 1, n);
	else
		ans += qry(1, a[x] - 1);
}

void remove(int x, bool side) {
	if(side)
    	ans -= qry(a[x] + 1, n);
    else
    	ans -= qry(1, a[x] - 1);
    upd(a[x], -1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> q;
    vector<int> b(n);
    vector<array<int, 3>> walls(q);
    for(int i = 0; i < n; i++) {
    	cin >> b[i];
    	a[i + 1] = b[i];
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 1; i <= n; i++) 
    	a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    set<int> st;
    st.insert(0);
    st.insert(n);
    vector<array<int, 2>> queries;
    for(int x, i = 0; i < q; i++) {
    	cin >> x;
    	auto it = st.lower_bound(x);
    	int r = *it, l = *--it;
    	walls[i] = {l + 1, r, x};
    	st.insert(x);
    	if(l + 1 != r) queries.push_back({l + 1, r});
    	if(l + 1 != x) queries.push_back({l + 1, x});
    	if(x + 1 != r) queries.push_back({x + 1, r});
    }
    queries.push_back({1, n});
    sort(queries.begin(), queries.end());
    queries.resize(unique(queries.begin(), queries.end()) - queries.begin());
    sort(queries.begin(), queries.end(), [&] (const array<int, 2> x, const array<int, 2> y) {
    	if(x[0] / block != y[0] / block) return x[0] / block < y[0] / block;
    	return (x[0] / block & 1) ? x[1] < y[1] : x[1] > y[1];
    });
    assert(queries.size() <= n);
    map<array<int, 2>, long long> inv;
    int l = 2, r = 1;
    for(auto tx : queries) {
    	int tl = tx[0], tr = tx[1];	
    	while(l > tl)
    		add(--l, 0);
    	while(r < tr)
    		add(++r, 1);
    	while(l < tl)
    		remove(l++, 0);
    	while(r > tr)
    		remove(r--, 1);
    	inv[tx] = ans;
    }
    long long now = inv[{1, n}];
    for(auto &tlrx: walls) {
    	int tl = tlrx[0], tr = tlrx[1], x = tlrx[2];
    	now = now - inv[{tl, tr}] + inv[{tl, x}] + inv[{x + 1, tr}];
    	cout << now << '\n';
    }
    return 0;
}