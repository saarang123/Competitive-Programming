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

const int N = 1e4+2;
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n >> m;
    vector<int> a[n+2];
    for(i=1; i<=n; i++) {
        int k; cin >> k;
        a[i].pb(0);
        while(k--) {
            int x; cin >> x;
            a[i].pb(x);
        }
    }
    vector<vector<int>> dp(n + 2, vector<int>(m+2, -1e8));
    vector<vector<int>> pref(n+2, vector<int>(102, 0));
    for(i=1; i<=n; i++) {
        for(j=1; j<a[i].size(); j++) a[i][j] += a[i][j-1];
    }
    //for(i=1; i<=n; i++) { for(int u: a[i]) cout << u <<  " "; cout << "\n";} cout << "----------\n";
    for(i=1; i<=n; i++) {
        int sz = a[i].size();
        for(j=1; j<sz; j++) {
            for(int k=0; k<=j; k++) {
                remax(pref[i][j], a[i][k] + a[i][sz - 1] - a[i][sz - 1 - j + k]);
            }
        }
    }
    /*for(i=1; i<=n; i++) {
        for(j=1; j<a[i].size(); j++) cout << pref[i][j] << " "; cout << "\n";
    } cout << "-------------\n";*/
    for(i=0; i<=n; i++) dp[i][0] = 0;
    for(i=0; i<=m; i++) dp[0][i] = 0;
    int total = 0;
    for(i=1; i<=n; i++) {
        total += (a[i].size());
        int sz = a[i].size();
        for(j=1; j<=min(total, m); j++) {
            for(int k=0; k<=min(j, sz - 1); k++) {
                remax(dp[i][j], pref[i][k] + dp[i - 1][j - k]);
            }
        }
    }
    /*for(i=0; i<=n; i++) {
        for(j=0; j<=m; j++) cout << dp[i][j] << " "; cout << "\n";
    }*/
    cout << dp[n][m] << "\n";
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
