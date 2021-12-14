template<class T> struct SparseTable { // comb(ID,b) = b
    T ID = T();
    function<T(const T&,const T&)> comb;
    int n, k; vector<vector<T>> seg;
    void init(int _n, T base, function<T(const T&,const T&)> join) {
        n = _n; k = lg(n); comb = join; ID = base; seg.assign(_n + 1, vector<T> (k + 1, ID)); }
    int lg(int x) { return 31 - __builtin_clz(x); }   //CHECK THIS
    void build(vector<T> a) {
        for(int i = 1; i <= n; i++) seg[i][0] = a[i];
        for(int j = 1; j <= k; j++)
            for(int i = 1; i + (1 << j) - 1 <= n; i++)
                seg[i][j] = comb(seg[i][j - 1], seg[i + (1 << (j - 1))][j - 1]);
    }
    T query(int L, int R) {
        int j = lg(R - L + 1);
        return comb(seg[L][j], seg[R - (1 << j) + 1][j]);
    }
};