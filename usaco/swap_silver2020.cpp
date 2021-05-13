#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 2;
int up[N][32];
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    vector<array<int, 2>> ranges(m);
    for(int i = 0; i < m; i++)
        cin >> ranges[i][0] >> ranges[i][1];
    for(int i = 0; i < m; i++)
        reverse(a.begin() + ranges[i][0] - 1, a.begin() + ranges[i][1]);
    for(int i = 0; i < n; i++) up[i][0] = a[i];
    for(int i = 1; i <= 31; i++) {
        for(int j = 0; j < n; j++)
            up[j][i] = up[up[j][i - 1]][i - 1];
    }
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    for(int i = 0; i < n; i++) {
        for(int j = 31; j >= 0; j--) {
            if(!(k & (1 << j))) continue;
            ans[i] = up[ans[i]][j];
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] + 1 << '\n';
    return 0;
}
