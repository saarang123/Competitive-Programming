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

const int N = 1e6+3;
int n,m;
int dp[(1<<3)+2][N];
string a[5];

void fix(int i) {
    int j;
    for(int mask=0; mask<(1<<n); mask++) {
        string tmp = "", cur = "";
        for(j=0; j<n; j++) {
            if(mask & (1<<j)) tmp += "1";
            else tmp += "0";
        }
        for(j=0; j<n; j++) cur += a[j][i];
        //cout << tmp << " " << cur << "\n";
        for(j=0; j<n; j++)
            dp[mask][i] += (tmp[j]!=cur[j]);
    }
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    cin >> n >> m;
    if(n>3)
        return void(cout << -1 << "\n");
    if(n==1)
        return void(cout << 0 << "\n");
    for(i=0; i<n; i++) {
        cin >> a[i];
    }
    if(n==2) {
        fix(0);
        for(i=1; i<m; i++) {
            fix(i);
            dp[0][i] += min(dp[1][i-1], dp[2][i-1]);
            dp[1][i] += min(dp[0][i-1], dp[3][i-1]);
            dp[2][i] += min(dp[0][i-1], dp[3][i-1]);
            dp[3][i] += min(dp[1][i-1], dp[2][i-1]);
        }
        int x = 1e9;
        for(i=0; i<(1<<n); i++) remin(x, dp[i][m-1]);
        return void(cout << x << "\n");
    }
    fix(0);
    //for(i=0; i<8; i++) cout << dp[i][0] << " "; cout << "\n";
    for(i=1; i<m; i++) {
        fix(i);
        dp[0][i] += min(dp[2][i-1], dp[5][i-1]);
        dp[1][i] += min(dp[3][i-1], dp[4][i-1]);
        dp[2][i] += min(dp[0][i-1], dp[7][i-1]);
        dp[3][i] += min(dp[1][i-1], dp[6][i-1]);
        dp[4][i] += min(dp[6][i-1], dp[1][i-1]);
        dp[5][i] += min(dp[0][i-1], dp[7][i-1]);
        dp[6][i] += min(dp[3][i-1], dp[4][i-1]);
        dp[7][i] += min(dp[2][i-1], dp[5][i-1]);
        //for(j=0; j<8; j++) cout << dp[j][i] << " "; cout << "\n";
    }
    int x = 1e9;
    for(i=0; i<(1<<n); i++) remin(x, dp[i][m-1]);
    cout << x << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
