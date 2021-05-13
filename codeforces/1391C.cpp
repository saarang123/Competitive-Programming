#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const int N = 1e6+2;
const int mod = 1e9+7;
int dp[N], f[N];
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    cin >> n;
    f[0] = 1;
    for(i=1; i<=n; i++) f[i] = (f[i-1]*i)%mod;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(i=4; i<=n; i++) dp[i] = (dp[i-1]*2 + mod)%mod;
    int ans = (f[n]-dp[n]+mod)%mod;
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
