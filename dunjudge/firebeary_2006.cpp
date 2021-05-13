#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 1;
const int N = 2002;
const vector<array<int, 2>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dt[N][N];
char a[N][N];

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    queue<array<int, 2>> q;
    array<int, 2> fire = {-1, -1};
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dt[i][j] = inf;
            if(a[i][j] == 'F')
                fire = {i, j};
            else if(a[i][j] == 'B') {
                q.push({i, j});
                dt[i][j] = 0;
            }
        }
    auto out = [&] (int x, int y) {
        return x < 1 || y < 1 || x > n || y > m;
    };
    auto dist = [&] (int x, int y) {
        return abs(x - fire[0]) + abs(y - fire[1]);
    };
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(auto [dx, dy] : dir) {
            if(out(x + dx, y + dy) || a[x + dx][y + dy] == '@')
                continue;
            if(dist(x, y) > dt[x][y] + 2 && dt[x + dx][y + dy] > dt[x][y] + 2) {
                dt[x + dx][y + dy] = dt[x][y] + 2;
                q.push({x + dx, y + dy});
            }   
        }
    }
    int answer = inf;
    for(int i : {1, n})
        for(int j = 1; j <= m; j++) if(a[i][j] != '@' && dt[i][j] + 2 < dist(i, j))
            answer = min(answer, dt[i][j]);
    for(int j : {1, m})
        for(int i = 1; i <= n; i++) if(a[i][j] != '@' && dt[i][j] + 2 < dist(i, j))
            answer = min(answer, dt[i][j]);
    cout << (answer ^ inf ? answer + 2 : -1) << '\n';
    return 0;
}