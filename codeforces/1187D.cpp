#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

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

void solve_case() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    Seg<int> st; st.init(n, n + 5, [&] (int x, int y) { return min(x, y);});
    vector<queue<int>> p(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        st.upd(i + 1, a[i]);
        p[a[i]].push(i + 1);
    }
    for(int &x : b) cin >> x;
    for(int i = 0; i < n; i++) {
        if(p[b[i]].empty())
            return void(cout << "NO\n");
        int x = p[b[i]].front(); p[b[i]].pop();
        if(st.query(1, x) < b[i]) return void(cout << "NO\n");
        st.upd(x, n + 5);
    }
    cout << "YES" << '\n';
}
