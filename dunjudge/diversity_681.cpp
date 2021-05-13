#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 5002;

template<class T> struct Seg { // comb(ID,b) = b
    T ID = T();
    function<T(const T&,const T&)> comb;
    int n; vector<T> seg;
    void init(int _n, T base, function<T(const T&,const T&)> join) {
        n = _n; comb = join; ID = base; seg.assign(2 * n, ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n - 1] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {    // sum on interval [l, r]
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
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    long long ans = 0;
    vector<int> dp(n + 1);
    return 0;
}