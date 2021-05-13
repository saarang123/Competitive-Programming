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
    int n; cin >> n;
    vector<int> a(n), b;
    for(int &x : a)
        cin >> x, x--;
    vector<bool> f(n);
    int i = n - 1;
    for(int t = n - 1; t >= 0;) {
        while(t >= 0 && f[t]) t--;
        if(t < 0) break;
        vector<int> c;
        while(i >= 0 && a[i] != t) {
            c.push_back(a[i]);
            f[a[i]] = true;
            i--;
        }
        c.push_back(a[i]);
        f[a[i]] = true; i--;
        reverse(c.begin(), c.end());
        for(int x : c) {
            b.push_back(x);
        }
    }
    for(int x : b)
        cout << x + 1 << ' ';
    cout << '\n';
}
