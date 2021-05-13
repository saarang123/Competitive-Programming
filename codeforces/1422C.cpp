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
const int mod = 1e9 + 7;
int f[N];

int cnt(int i) { return (i * (i + 1)/2) % mod; }

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    string s;
    cin >> s;
    n = s.size();
    f[0] = 1;
    for(i = 1; i <= n; i++)
        f[i] = f[i - 1] * 10, f[i] %= mod;
    int sum = 0;
    for(char c : s) sum += (c - '0');
    int ans = 0;
    for(i = 0; i < n; i++) {
        int mx = cnt(i) * f[n - i - 1] * (s[i] - '0');
        mx %= mod;
        ans += mx;
        ans %= mod;
    }
    reverse(all(s));
    for(i = 0; i < n; i++) {
        sum -= (s[i] - '0');
        int mx = (f[i] * sum) % mod * (i + 1); mx %= mod;
        ans += mx;
        ans %= mod;
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
