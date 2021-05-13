#include <bits/stdc++.h>
using namespace std;

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }

const int N = 17;
int dp[101][1 << N];
array<int, 2> par[101][1 << N];
int cost[1 << N];
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < 60; i++)
        for(int j = 0; j < 17; j++)
            if(i % primes[j] == 0)
                cost[i] |= (1 << j);
    for(int i = 0; i <= n; i++) for(int m = 0; m < (1 << 17); m++) dp[i][m] = 1e9;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < 60; j++) {
            int x = cost[j] ^ ((1 << 17) - 1);
            for(int smask = x; smask; smask = (smask - 1) & x) {
                if(remin(dp[i][smask | cost[j]], dp[i - 1][smask] + abs(a[i] - j)))
                    par[i][smask | cost[j]] = {j, smask};
            }
            if(remin(dp[i][cost[j]], dp[i - 1][0] + abs(a[i] - j)))
                par[i][cost[j]] = {j, 0};
        }
    }
    int id = 1;
    for(int m = 0; m < (1 << 17); m++) if(dp[n][m] < dp[n][id]) id = m;
    //cout << dp[n][id] << '\n';
    function<void(int i, int mask)> out = [&] (int i, int mask) {
        if(i == 0) return;
        b[i] = par[i][mask][0];
        out(i - 1, par[i][mask][1]);
    };
    out(n, id);
    for(int i = 1; i <= n; i++) cout << b[i] << ' '; cout << '\n';
    return 0;
}
