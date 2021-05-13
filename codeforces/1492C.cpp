#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> id[26], p(m), sf(m);
    for(int i = 0; i < n; i++) {
        id[s[i] - 'a'].push_back(i + 1);
    }
    p[0] = id[t[0] - 'a'][0];
    for(int i = 1; i < m; i++) {
        auto x = upper_bound(id[t[i] - 'a'].begin(), id[t[i] - 'a'].end(), p[i - 1]);
        p[i] = *x;
    }
    sf[m - 1] = id[t.back() - 'a'].back();
    for(int i = m - 2; i >= 0; i--) {
        auto x = lower_bound(id[t[i] - 'a'].begin(), id[t[i] - 'a'].end(), sf[i + 1]);
        if(x == id[t[i] - 'a'].end()) x--;
        if(*x >= sf[i + 1]) x--;
        sf[i] = *x;
    }
    int ans = 0;
    for(int i = 1; i < m; i++) {
        ans = max(ans, sf[i] - p[i - 1]);
    }
    cout << ans << '\n';
}
