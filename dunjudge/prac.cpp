#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dt(n, vector<int> (n, inf));
    for(int a, b, c, _ = 0; _ < m; _++) {
        cin >> a >> b >> c;
        a--, b--;
        dt[a][b] = min(dt[a][b], c);
        dt[b][a] = min(dt[b][a], c);
    }
    for(int i = 0; i < n; i++)
        dt[i][i] = 0;
    for(int k = 0; k < n; k++) 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dt[i][j] = min(dt[i][j], dt[i][k] + dt[k][j]);
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << (dt[a][b] >= inf ? -1 : dt[a][b]) << '\n';
    }
    return 0;
}