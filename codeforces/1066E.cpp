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
const int N = 2e5 + 2;
const int mod = 998244353;
int p[N];
void solve_case() {
    p[0] = 1;
    for(int i = 1; i < N; i++) p[i] = p[i - 1] * 2, p[i] %= mod;
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    reverse(all(s)); reverse(all(t));
    while(s.size() < t.size()) s += "0";
    while(t.size() < s.size()) t += "0";
    reverse(all(s)); reverse(all(t));
    int ans = 0, c = 0;
    n = max(n, m);
    for(int i = 0; i < n; i++) {
        c += (t[i] == '1');
        if(s[i] == '1') (ans += (c * p[n - i - 1]) % mod) %= mod;
    }
    cout << ans << '\n';
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
