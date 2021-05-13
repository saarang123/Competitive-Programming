#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200 * 1000 + 3;
const int mod = 1e9 + 7;
const long long base = 18492477;
map<int, int> cnt[mxn];
int t[mxn << 2];
long long a[mxn], po[mxn];
int n, m;

void build(int v, int tl, int tr) {
    if(tl == tr)
        t[v] = 1;
    else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1|1, tm + 1, tr);
        t[v] = t[v << 1] + t[v << 1|1];
    }
}

void update(int v, int tl, int tr, int pos, int x) {
    if(tl == tr) {
        a[tl] = (a[tl] + x + mod) % mod;
        t[v] = !a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    if(pos <= tm)
        update(v << 1, tl, tm, pos, x);
    else
        update(v << 1|1, tm + 1, tr, pos, x);
    t[v] = t[v << 1] + t[v << 1|1];
}

void upd(int p, int x) { update(1, 1, n, p, x); }

int query(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(tl == l && tr == r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return query(v << 1, tl, tm, l, min(tm, r)) + query(v << 1|1, tm + 1, tr, max(tm + 1, l), r);
}

int query(int l, int r) { return query(1, 1, n, l, r); }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    po[0] = 1;
    for(int i = 1; i < mxn; i++)
        po[i] = po[i - 1] * base, po[i] %= mod;
    cin >> n >> m;
    assert(n < mxn && m < mxn);
    build(1, 1, n);
    while(m--) {
        int tp; cin >> tp;
        if(tp == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            upd(l, po[x]);
            if(r < n)
                upd(r + 1, -po[x]);
        } else {
            int l, r;
            cin >> l >> r;
            cout << (query(l + 1, r) == r - l ? 1 : 0) << '\n';
        }
    }
    return 0;
}