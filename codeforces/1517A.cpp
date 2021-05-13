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

vector<long long> t;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    long long c = 2050;
    while(c < (long long) 1e18) {
        t.push_back(c);
        c *= 10;
    }
    reverse(t.begin(), t.end());
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    long long n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < t.size() && n; i++) {
        while(n >= t[i]) {
            n -= t[i];
            cnt++;
        }
    }
    if(n != 0)
        cout << -1 << '\n';
    else
        cout << cnt << '\n';
}
