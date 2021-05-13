#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 2, mxa = 1000 * 1000 + 2;
const int block = 450;

struct Query {
	int l, r, idx;
	bool operator < (Query other) const {
		if(l / block != other.l / block)
			return l < other.l;
		return (l / block & 1) ? (r < other.r) : (r > other.r);
	}
};

long long a[mxn], c[mxa], ans = 0;

void add(int i) {
	ans -= c[a[i]] * c[a[i]] * a[i];
	c[a[i]]++;
	ans += c[a[i]] * c[a[i]] * a[i];
}

void remove(int i) {
	ans -= c[a[i]] * c[a[i]] * a[i];
	c[a[i]]--;
	ans += c[a[i]] * c[a[i]] * a[i];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, t;
    cin >> n >> t;
    vector<long long> o(t);
    vector<Query> q(t);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(int l, r, i = 0; i < t; i++) {
    	cin >> l >> r;
    	l--,r--;
    	q[i] = {l, r, i};
    }
    sort(q.begin(), q.end());
    int l = 0, r = -1;
    for(Query cur : q) {
    	while(l > cur.l) 
    		add(--l);
    	while(r < cur.r) 
    		add(++r);
    	while(l < cur.l) 
    		remove(l++);
    	while(r > cur.r) 
    		remove(r--);
    	o[cur.idx] = ans;
    }
    for(auto &x : o)
    	cout << x << '\n';
    return 0;
}