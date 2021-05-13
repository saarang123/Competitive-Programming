#include <bits/stdc++.h>
using namespace std;
const int mxn = 77;
int a[mxn];
long long dp[2][mxn][mxn][3][mxn][3], cmin[2][mxn][mxn][3][2];
int n, m;

inline bool is(int x, int y, int z) {
    return (x < y && y > z) || (x > y && y < z);
}

inline void remin(long long &x, const long long &y) {
        x = min(x, y);
}

inline bool valid(int x, int y, int z) {
    return x != y && y != z;
}
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    memset(dp, 0x0f, sizeof dp);
    memset(cmin, 0x0f, sizeof cmin);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];
    if(m == 0) {
        int cnt = 0;
        for(int i = 2; i < n; i++) {
            cnt += is(a[i - 1], a[i], a[i + 1]);
            if(a[i] == a[i - 1] || a[i] == a[i + 1]) {
                cnt = -1; break;
            }
        }
        cout << cnt << '\n';
        return 0;
    }
    if(n <= 2)
        return cout << 0 << '\n', 0;
    assert(m > 0 && n > 2);
    for(int x = 1; x <= n; x++)
        for(int d1 = -1; d1 <= 1; d1++)
            for(int y = 1; y <= n; y++)
                for(int d2 = -1; d2 <= 1; d2++)
                    if((a[x] + d1) != (a[y] + d2)) {
                        dp[0][0][x][d1 + 1][y][d2 + 1] = abs(a[1] - (a[x] + d1)) + abs(a[2] - (a[y] + d2));
                        remin(cmin[0][0][y][d2 + 1][(a[x] + d1) < (a[y] + d2)], dp[0][0][x][d1 + 1][y][d2 + 1]);
                    }
    for(int i = 3; i <= n; i++) {
        memset(dp[i & 1], 0x0f, sizeof dp[i & 1]);
        memset(cmin[i & 1], 0x0f, sizeof cmin[i & 1]);
        for(int j = 0; j < i; j++) {
            for(int z = 1; z <= n; z++)
            for(int d3 = -1; d3 <= 1; d3++)
            for(int y = 1; y <= n; y++)
            for(int d2 = -1; d2 <= 1; d2++) {
                int p = a[y] + d2, q = a[z] + d3;
                if(p == q) continue;
                if(p > q) {
                    remin(dp[i & 1][j][y][d2 + 1][z][d3 + 1], abs(a[i] - q) + cmin[(i & 1) ^ 1][j][y][d2 + 1][0]);
                    remin(dp[i & 1][j + 1][y][d2 + 1][z][d3 + 1], abs(a[i] - q) + cmin[(i & 1) ^ 1][j][y][d2 + 1][1]);
                } else {
                    remin(dp[i & 1][j][y][d2 + 1][z][d3 + 1], abs(a[i] - q) + cmin[(i & 1) ^ 1][j][y][d2 + 1][1]);
                    remin(dp[i & 1][j + 1][y][d2 + 1][z][d3 + 1], abs(a[i] - q) + cmin[(i & 1) ^ 1][j][y][d2 + 1][0]);
                }
                //remin(cmin[i & 1][j][z][d3 + 1][p < q], dp[i & 1][j][y][d2 + 1][z][d3 + 1]);
                //remin(cmin[i & 1][j][z][d3 + 1][p < q], m + 1);
                //cout << "I: " << i << ' ' << "Cnt: " << j << ' ' << p << ' ' << q << ": " << dp[i & 1][j][y][d2 + 1][z][d3 + 1] << '\n';
            }
        }
        for(int j = 0; j <= i; j++) {
            for(int z = 1; z <= n; z++)
            for(int d3 = -1; d3 <= 1; d3++)
            for(int y = 1; y <= n; y++)
            for(int d2 = -1; d2 <= 1; d2++) {
                int p = a[y] + d2, q = a[z] + d3;
                if(p == q) continue;
                remin(cmin[i & 1][j][z][d3 + 1][p < q], dp[i & 1][j][y][d2 + 1][z][d3 + 1]);
                remin(cmin[i & 1][j][z][d3 + 1][p < q], m + 1);
            }
        }
    }
    for(int i = 0; i <= n; i++) 
        for(int x = 1; x <= n; x++)
            for(int d1 = -1; d1 <= 1; d1++)
                if(cmin[n & 1][i][x][d1 + 1][0] <= m || cmin[n & 1][i][x][d1 + 1][1] <= m)
                    return cout << i << '\n', 0;
    cout << -1 << '\n';
    return 0;
}