#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 2;
int dp[N], t[4 * N];

void upd(int v, int tl, int tr, int x, int val) {
    if(tl == tr)
        return void(t[v] = val);
    int tm = (tl + tr) >> 1;
    if(x <= tm) upd(v << 1, tl, tm, x, val);
    else upd(v << 1|1, tm + 1, tr, x, val);
    t[v] = max(t[v << 1], t[v << 1|1]);
}

int qry(int v, int tl, int tr, int l, int r) {
    if(l > r) return 0;
    if(l <= tl && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return max(
               qry(v << 1, tl, tm, l, min(tm, r)),
               qry(v << 1|1, tm + 1, tr, max(tm + 1, l), r)
               );
}

int qry(int l, int r) { return qry(1, 1, N - 2, l, r); }

void upd(int x, int v) { upd(1, 1, N - 2, x, v); }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1), h(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = a[1];
    upd(h[1], dp[1]);
    int ans = dp[1];
    for(int i = 2; i <= n; i++) {
        dp[i] = a[i] + qry(1, h[i] - 1);
        upd(h[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    return 0;
}
