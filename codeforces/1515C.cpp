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
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, m, x;
    cin >> n >> m >> x;
    multiset<array<int, 2>> s;
    vector<int> o(n);
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end(), greater<>());
    for(int i = 0; i < m; i++)
        s.insert({0, i + 1});
    vector<int> ok(m);
    for(auto &[val, i] : a) {
        auto [sum, id] = *s.begin();
        s.erase(s.begin());
        o[i] = id;
        sum += val;
        ok[id - 1] = sum;
        s.insert({sum, id});
    }
    sort(ok.begin(), ok.end());
    if(ok.back() - ok[0] > x)
        cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';
        for(int i = 0; i < n; i++)
            cout << o[i] << ' ';
        cout << '\n';
    }
}
