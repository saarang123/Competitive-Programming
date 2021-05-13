#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxn = 300 * 1000 + 3;
long long bit[mxn];
int target[mxn], ans[mxn];
vector<int> lands[mxn];
vector<array<int, 3>> event;
int n, m, k;

void upd(int x, int v) {
	for(; x <= m; x += x & -x)
		bit[x] += v;
}

void update(int l, int r, int v) {
	upd(r + 1, -v);
	upd(l, v);
	if(l > r)
		upd(1, v), upd(m + 1, -v);
}

long long query(int x) {
	long long res = 0;
	for(; x; x -= x & -x)
		res += bit[x];
	return res;
}

void pbs(int l, int r, vector<int> &q) {
	if(q.empty()) return;
	if(l == r) {
		for(int i : q)
			ans[i] = l;
		return;
	}
	int mid = (l + r) >> 1;
	for(int i = l; i <= mid; i++) {
		auto [tl, tr, a] = event[i];
		update(tl, tr, a);
	}
	vector<int> left, right;
	for(int c : q) {
		unsigned long long sum = 0;
		for(int x : lands[c])
			sum += query(x);
		if(sum >= target[c])
			left.push_back(c);
		else {
			target[c] -= sum;
			right.push_back(c);
		}
	}
	for(int i = l; i <= mid; i++) {
		auto [tl, tr, a] = event[i];
		update(tl, tr, -a);
	}
	pbs(l, mid, left);
	pbs(mid + 1, r, right);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    for(int x, i = 1; i <= m; i++) {
    	cin >> x;
    	lands[x].push_back(i);
    }
    for(int i = 1; i <= n; i++)
    	cin >> target[i];
    cin >> k;
    for(int l, r, a, i = 0; i < k; i++) {
    	cin >> l >> r >> a;
    	event.push_back({l, r, a});
    }
    vector<int> all(n);
    iota(all.begin(), all.end(), 1);
    pbs(0, k, all);

    for(int i = 1; i <= n; i++) {
    	if(ans[i] == k)
    		cout << "NIE" << '\n';
    	else
    		cout << ans[i] + 1 << '\n';
    }
    return 0;
}