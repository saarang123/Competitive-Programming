#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const int mod = 1e9 + 7;
const int N = 2e5 + 2;
int a[N], c[N], q[N], p[N];

int f(int i) { return max(0LL, i); };

void solve_case() {
    int n,i,j;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    p[0] = 1;
    for(i = 1; i <= n + 1; i++) {
        a[i] = a[i - 1] + (s[i] == 'a');
        q[i] = q[i - 1] + (s[i] == '?');
        c[i] = c[i - 1] + (s[i] == 'c');
        p[i] = p[i - 1] * 3; p[i] %= mod;
    }
    int ans = 0;
    int cnt = q[n];
    for(i = 1; i <= n; i++) {
        if(s[i] == 'b') {
            int nxt;
            ans += (a[i] * (c[n] - c[i])) % mod * p[cnt] % mod; //abc
            ans %= mod;
            ans += (a[i] * (q[n] - q[i])) % mod * p[f(cnt - 1)] % mod; //ab?
            ans %= mod;
            ans += (q[i] * (c[n] - c[i])) % mod * p[f(cnt - 1)] % mod; //?bc
            ans %= mod;
            ans += (q[i] * (q[n] - q[i])) % mod * p[f(cnt - 2)] % mod; //?b?
            ans %= mod;
        }
        else if(s[i] == '?') {
            ans += (a[i] * (c[n] - c[i])) % mod * p[f(cnt - 1)] % mod;  //a?c
            ans %= mod;
            ans += (a[i] * (q[n] - q[i])) % mod * p[f(cnt - 2)] % mod; //a??
            ans %= mod;
            ans += (q[i - 1] * (c[n] - c[i])) % mod * p[f(cnt - 2)] % mod; //??c
            ans %= mod;
            ans += (q[i - 1] * (q[n] - q[i])) % mod * p[f(cnt - 3)] % mod; //???
            ans %= mod;
        }
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
