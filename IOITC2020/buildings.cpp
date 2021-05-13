#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;

struct Line {
    long long m, c;
    Line() : m(0), c(inf) {}
    Line(long long _m, long long _c) : m(_m), c(_c) {}
    long long operator () (long long x) {
        return m * x + c;
    }
};

const int MXN = 1000 * 1000 + 3;
Line t[4 * MXN];
stack<pair<int, Line>> used;

void insert(int v, int l, int r, Line nxt) {
    int m = (l + r) >> 1;
    bool lef = t[v](l) > nxt(l);
    bool mid = t[v](m) > nxt(m);
    if(mid) {
        used.push({v, t[v]});
        swap(t[v], nxt);
    }
    if(l == r) return;
    if(lef != mid)
        insert(v << 1, l, m, nxt);
    else
        insert(v << 1|1, m + 1, r, nxt);

}

void insert(Line nxt) {
    insert(1, 0, MXN, nxt);
}

long long query(int v, int l, int r, int x) {
    int m = (l + r) >> 1;
    if(l == r)
        return t[v](x);
    if(x <= m)
        return min(t[v](x), query(v << 1, l, m, x));
    return min(t[v](x), query(v << 1|1, m + 1, r, x));
}

long long query(int x) {
    return query(1, 0, MXN, x);
}

void solve() {
    int n; cin >> n;
    vector<array<long long, 3>> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    sort(a.begin() + 1, a.end());
    int start = -1, end = -1;
    for(int i = 1; i <= n; i++) {
        if(a[i][2] == 1)
            start = i;
        if(a[i][2] == n)
            end = i;
    }
    vector<long long> dp(n + 1, 1e15);
    for(int i = 1; i <= start; i++) {
        dp[i] = 0;
        insert({a[i][1], dp[i] - a[i][0] * a[i][1]});
    }
    for(int i = start + 1; i <= end; i++) {
        dp[i] = query(a[i][0]);
        insert({a[i][1], dp[i] - a[i][0] * a[i][1]});
    }
    cout << dp[end] << '\n';
    while(!used.empty()) {
        auto &[v, x] = used.top();
        t[v] = x;
        used.pop();
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tc; cin >> tc;
    while(tc--)
        solve();
    return 0;
}