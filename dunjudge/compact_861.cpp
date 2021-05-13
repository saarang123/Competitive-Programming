#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar();
        }
    return x;
}

template<class T> struct Segmx { // comb(ID,b) = b
	const T ID = 0; T comb(T a, T b) { return max(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n - 1] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n-1, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
	void build(int a[]) {
        for(int i = 1; i <= n; i++) seg[n + i - 1] = a[i];
        for(int i = n - 1; i > 0; i--) seg[i] = comb(seg[i << 1], seg[i << 1|1]);
	}
};

template<class T> struct Segmn { // comb(ID,b) = b
	const T ID = 1e9 + 10; T comb(T a, T b) { return min(a,b); }
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n - 1] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// sum on interval [l, r]
		T ra = ID, rb = ID;
		for (l += n-1, r += n; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
	void build(int a[]) {
        for(int i = 1; i <= n; i++) seg[n + i - 1] = a[i];
        for(int i = n - 1; i > 0; i--) seg[i] = comb(seg[i << 1], seg[i << 1|1]);
	}
};

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, l, d;
    n = scan(); l = scan(); d = scan();
    int h[n + 1], dp[n + 1];
    for(int i = 1; i <= n; i++) h[i] = scan();
    Segmx<int> sg1; sg1.init(n);
    Segmn<int> sg2; sg2.init(n);
    sg1.build(h); sg2.build(h);
    auto check = [&] (int i, int j) {
        return sg1.query(i, j) - sg2.query(i, j) <= d;
    };
    dp[0] = 0;
    Segmn<int> out; out.init(n);
    for(int i = l; i <= n; i++) {
        dp[i] = 1e9 + 10;
        if(!check(i - l + 1, i)) {
            out.upd(i, dp[i]); continue;
        }
        int mn = 1, mx = i - l + 1;
        while(mn < mx) {
            int mid = (mn + mx) / 2;
            if(check(mid, i))
                mx = mid;
            else
                mn = mid + 1;
        }
        if(mn == 1) {
            dp[i] = 1;
        } else {
            dp[i] = 1 + out.query(mn - 1, i - l);
        }
        out.upd(i, dp[i]);
    }
    cout << (dp[n] >= 1e9 ? -1 : dp[n]) << '\n';
}
