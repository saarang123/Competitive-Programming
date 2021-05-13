#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define int long long
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 302;
int g[N][N], n;
bool vis[N];

bool dfs(int v, int to) {
    if(v == to) return true;
    if(vis[v]) return false;
    vis[v] = true;
    for(int i = 1; i <= n; i++)
        if(g[v][i])
            if(dfs(i, to)) return true;
    return false;
}

void solve_case() {
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i + 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c; cin >> c;
            g[i + 1][j + 1] = c - '0';
        }
    }
    vector<int> used(n + 1, -1);
    for(int i = 1; i <= n; i++) {
        int id = a[i];
        for(int j = 1; j <= n; j++) {
            if(used[j] != -1) continue;
            memset(vis, 0, sizeof vis);
            if(dfs(id, j)) {
                used[j] = i;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << used[i] << ' '; cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcases = 1;
    //cin >> testcases;
    while(testcases--) {
        solve_case();
    }
}
