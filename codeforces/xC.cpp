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
const int mod = 1e9 + 7;
const int N = 5001;
int dp[N][N], go[N][N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,k;
    n = 5000; k = 5000;
    vector<int> a(n+2);
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++)
            dp[i][j] = 0;
            go[i][j] = 0;
    }
    for(i = 1; i <= n; i++) dp[i][0] = a[i], go[i][0] = 1;
    for(j = 1; j <= k; j++) {
        for(i = 1; i <= n; i++) {
            if(i == 1)
                go[i][j] = go[i + 1][j - 1] % mod;
            else if(i == n)
                go[i][j] = go[i - 1][j - 1] % mod;
            else {
                go[i][j] = go[i - 1][j - 1] + go[i + 1][j - 1];
                go[i][j] %= mod;
            }
        }
    }
    for(j = 1; j <= k; j++) {
        for(i = 1; i <= n; i++){
            if(i == 1) {
                dp[i][j] = (go[i][j] * a[i]) % mod + dp[i + 1][j - 1];
                dp[i][j] %= mod;
            }
            else if(i == n) {
                dp[i][j] = (go[i][j] * a[i]) % mod + dp[i - 1][j - 1];
                dp[i][j] %= mod;
            }
            else {
                dp[i][j] = (go[i][j] * a[i]) % mod + dp[i - 1][j - 1] + dp[i + 1][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    /*
    cout << "GO: \n";
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) cout << go[i][j] << " ";
        cout << "\n";
    }
    cout << "DP: \n";
    for(i = 1; i <= n; i++) {
        for(j = 0; j <= k; j++) cout << dp[i][j] << " ";
        cout << "\n";
    }
    */
    int x; cin >> x;
    while(x--) {
        cin >> n >> k;
        int ans = 0;
        for(i = 1; i <= n; i++) {
            ans += dp[i][k];
            ans %= mod;
        }
        cout << ans << "\n";
    }
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
