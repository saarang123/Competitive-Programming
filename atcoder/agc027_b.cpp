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
const int N = 2003;
int cost[N][N], a[N], dp[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    for(i = n; i; i--) {
        for(j = i; j; j--) {
            cost[j][i] = cost[j + 1][i] + ((i - j + 1) * (i - j + 1) * (a[i] - a[j]));
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = i; j <= n; j++) cout z<< cost[i][j] << " "; cout << "\n";
    }
    for(i = 1; i <= n; i++) {
        dp[i] = 1e18;
    }
    for(i = 1; i <= n; i++) {
        dp[i] = cost[1][i] + m * i + ((i + 1) * (i + 1) * a[1]) + a[1];
        cout << "initial: " << dp[i] << "\n";
        for(j = 1; j < i; j++) {
            dp[i] = min(dp[i], cost[j][i] + dp[j] + m * i + ((j - i + 1) * (j - i + 1) * a[j]) + a[i]);
        }
    }
    for(i = 0; i <= n; i++) cout << i << " " << dp[i] << "\n";
    cout << dp[n] << "\n";
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
