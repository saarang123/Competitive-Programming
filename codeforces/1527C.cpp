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
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n; cin >> n;
    vector<int> a(n + 1), dp(n + 1);
    map<int, vector<int>> cnt;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }
    long long ans = 0;
    for(auto [x, o] : cnt) {
        long long sum = 0;
        for(int id : o)
            sum += (n - id + 1);
        for(int id : o) {
            sum -= (n - id + 1);
            ans += (long long) id * sum;
        }
    }
    cout << ans << '\n';
}
