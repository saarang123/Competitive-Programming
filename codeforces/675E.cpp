#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const int N = 1e5 + 2;
vector<int> a(N), dp(N);
pair<int, int> t[4 * N];
int ans = 0, n;

void build(int v, int tl, int tr) {
    if(tl == tr)
        return void(t[v] = mp(a[tl], tl));
    int tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build(v << 1|1, tm + 1, tr);
    t[v] = max(t[v << 1], t[v << 1|1]);
}

pair<int, int> qry(int v, int tl, int tr, int l, int r) {
    if(l > r) return mp(0, 0);
    if(tl >= l && tr <= r)
        return t[v];
    int tm = (tl + tr) >> 1;
    return max(qry(v << 1, tl, tm, l, min(tm, r)),
               qry(v << 1|1, tm + 1, tr, max(tm + 1, l), r));
}

//int qry(int l, int r) { return qry(1, 1, n, l, r); }

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    cin >> n;
    for(i = 1; i < n; i++)
        cin >> a[i];
    a[n] = n;
    build(1, 1, n);
    dp[n] = 0;
    for(i = n - 1; i; i--) {
        int m = qry(1, 1, n, i + 1, a[i]).second;
        dp[i] = dp[m] - (a[i] - m) + n - i;
        ans += dp[i];
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
