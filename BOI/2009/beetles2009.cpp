#include <bits/stdc++.h>
using namespace std;
const int N = 302;
int a[N], r[N][N][2], l[N][N][2];
//[i, j] not included, right/left start point
signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    n++;
    a[n] = 0;
    sort(a + 1, a + n + 1);
    int start = lower_bound(a + 1, a + n + 1, 0) - a;
    memset(l, 0x3f, sizeof(l));
    memset(r, 0x3f, sizeof(r));
    for(int i = 1; i <= start; i++)
        for(int j = start; j <= n; j++)
            l[i][j][0] = r[i][j][0] = 0;
    int ans = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= start; i++)
            for(int j = start; j <= n; j++) {
                l[i][j][k & 1] = min(l[i - 1][j][(k & 1) ^ 1] + k * (a[i] - a[i - 1]), r[i][j + 1][(k & 1) ^ 1] + k * (a[j + 1] - a[i]));
                r[i][j][k & 1] = min(l[i - 1][j][(k & 1) ^ 1] + k * (a[j] - a[i - 1]), r[i][j + 1][(k & 1) ^ 1] + k * (a[j + 1] - a[j]));
            }
        ans = max(ans, k * m - l[start][start][k & 1]);
    }
    cout << ans << '\n';
}