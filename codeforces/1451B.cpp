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

void solve_case() {
    int n, q;
    cin >> n >> q;
    string s; cin >> s;
    s = " " + s;
    while(q--) {
        int l, r;
        cin >> l >> r;
        bool found = false;
        for(int i = 1; i < l; i++) found = found || (s[i] == s[l]);
        for(int i = n; i > r; i--) found = found || (s[i] == s[r]);
        cout << (found ? "YES\n" : "NO\n");
    }
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
