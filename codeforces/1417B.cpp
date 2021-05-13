#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve_case() {
    int n,i,j,m;
    cin >> n >> m;
    vector<int> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];
    vector<int> c(n, -1);
    map<int, vector<int>> cnt;
    set<int> st;
    for(i = 0; i < n; i++) {
        cnt[a[i]].pb(i);
        st.insert(a[i]);
    }
    set<int> seen;
    for(int x: st) {
        if(seen.count(x))
            continue;
        for(int v: cnt[x])
            c[v] = 0;
        for(int v : cnt[m - x])
            c[v] = 1;
        seen.insert(x);
        seen.insert(m - x);
        if(x == m - x) {
            for(i = 0; i < cnt[x].size(); i += 2)
                c[cnt[x][i]] = 0;
            for(i = 1; i < cnt[x].size(); i += 2)
                c[cnt[x][i]] = 1;
        }
    }
    for(int x: c) cout << x << " "; cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
