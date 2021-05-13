#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define int long long
const int inf = 1e14;
template<class T> struct Seg { // comb(ID,b) = b
	T ID = T();
    T comb(T x, T y) { return min(x, y); }
	int n; vector<T> seg;
	void init(int _n, T base) {
	    n = _n; ID = base; seg.assign(2 * n, ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		p += n - 1;
		seg[p] = min(seg[p], val); for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n-1, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
	void build(vector<T> a) {
        for(int i = 1; i <= n; i++) seg[n + i - 1] = a[i];
        for(int i = n - 1; i > 0; i--) seg[i] = comb(seg[i << 1], seg[i << 1|1]);
	}
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), p(n + 1);
    for(int i = 1; i <= n; i++) {
    	cin >> a[i]; p[i] = a[i];
    	if(i)
    		p[i] += p[i - 1];
    }
    vector<int> b = p;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    Seg<int> st; st.init(n + 5, inf);
    auto id = [&] (int x) {
    	return upper_bound(b.begin(), b.end(), x) - b.begin();
    };
    array<int, 2> length = {0, 0};
    for(int i = 1; i <= n; i++) if(a[i] <= m) {
    	length = {-1, i}; break;
    }
    st.upd(id(0), 0);
    for(int i = 1; i <= n; i++) {
    	st.upd(id(p[i]), i);
    	int j = lower_bound(b.begin(), b.end(), p[i] - m) - b.begin();
    	int index = st.query(j + 1, n + 2);
    	if(index <= n) 
    		length = min(length, {index - i, index + 1});
    }
    cout << -length[0] << ' ' << length[1] << '\n';
    return 0;
}