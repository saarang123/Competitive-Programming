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

const int N = 2e5+2;
int a[N], n, dp[N][2];

int f(int i, int j) {
    if(i > n)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == n) {
        if(j == 1) return dp[i][j] = 0;
        return dp[i][j] = a[i];
    }
    if(j == 1) {
        return dp[i][j] = min(f(i+1, 0), f(i+2, 0));
    }
    int cost = 0;
    cost += a[i];
    dp[i][j] = cost + f(i+1, 1);
    cost += a[i+1];
    remin(dp[i][j], cost + f(i+2, 1));
    return dp[i][j];
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    cin >> n;
    for(i=1; i<=n; i++) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = -1;
    }
    cout << f(1, 0) << "\n";
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
