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

const int N = 71;
int a[N][N];
int c[N][N];           //c[number of elements][mod] = max sum
int dp[N][N][N * N];  //dp[row][column][sum] = number of elements
int go[N][N];        //go[row][mod] = max sum for first k rows
int n, m, k;

void knapsack(int id) {
    int i,j;
    for(i = 0; i <= m; i++) for(j = 0; j < N * N; j++) dp[id][i][j] = 1e8;
    for(i = 0; i <= m; i++) dp[id][i][0] = 0;
    for(i = 1; i <= m; i++) {
        for(j = 1; j < N * N; j++) {
            if(j == 0)
                dp[id][i][j] = 0;
            else if(a[id][i] <= j)
                dp[id][i][j] = min(dp[id][i - 1][j], dp[id][i - 1][j - a[id][i]] + 1);
            else
                dp[id][i][j] = dp[id][i - 1][j];
        }
    }
    for(i = 1; i <= m; i++) {
        for(j = 1; j < N * N; j++) {
            if(dp[id][i][j] <= m / 2)
                remax(c[id][j % k], j);
        }
    }
}

void solve_case() {
    int i,j;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) for(j = 0; j <= k; j++) c[i][j] = -1;
    for(i = 1; i <= n; i++) for(j = 1; j <= m; j++) cin >> a[i][j];
    for(i = 1; i <= n; i++) knapsack(i);
    for(i = 0; i < k; i++) go[1][i] = c[1][i];
    for(i = 2; i <= n; i++) {
        for(j = 0; j < k; j++) go[i][j] = go[i - 1][j];
        for(j = 0; j < k; j++) remax(go[i][j], c[i][j]);
        for(j = 0; j < k; j++) {
            for(int k1 = 0; k1 < k; k1++) {
                if(go[i - 1][j] <= 0 || c[i][k1] == -1) continue;
                remax(go[i][(j + k1) % k], go[i - 1][j] + c[i][k1]);
            }
        }
    }
    int ans = -1e8;
    for(i = 1; i <= n; i++) remax(ans, go[i][0]);
    cout << (ans == -1 ? 0 : ans) << "\n";
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
