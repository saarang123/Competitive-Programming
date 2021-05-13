#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e8;

template<class T> struct Seg { // comb(ID,b) = b
	T ID = T();
    function<T(const T&,const T&)> comb;
	int n; vector<T> seg;
	void init(int _n, T base, function<T(const T&,const T&)> join) {
	    n = _n; comb = join; ID = base; seg.assign(2 * n, ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		p += n - 1;
		seg[p] = comb(seg[p], val); for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n-1, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
	void build(vector<int> a) {
        for(int i = 1; i <= n; i++) seg[n + i - 1] = a[i];
        for(int i = n - 1; i > 0; i--) seg[i] = comb(seg[i << 1], seg[i << 1|1]);
	}
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<int> a(n + 1), dp(n + 1, -inf), pref(n + 1);
    for(int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = (c == 'J' ? 1 : -1);
        pref[i] = pref[i - 1] + a[i];
    }
    Seg<int> st;
    st.init(2 * n, -inf, [&](int x, int y) {
        return max(x, y);
    });
    dp[l] = (pref[l] > 0 ? 1 : -1);
    for(int i = l + 1; i <= n; i++) {
        st.upd(pref[i - l] + n, dp[i - l]);
        dp[i] = max(1 + st.query(1, pref[i] - 1 + n), -1 + st.query(pref[i] + n, 2 * n));
        dp[i] = max(dp[i], (pref[i] > 0 ? 1LL : -1LL));
    }
    cout << dp[n] << '\n';
    return 0;
}
