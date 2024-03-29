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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,m;
    cin >> n >> m;
    vector<int> f[n * m + 2];
    int a[n][m], b[m][n], c[n][m];
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cin >> a[i][j];
            f[a[i][j]].pb(i);
        }
    }
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for(i = 0; i < n; i++) {
        int x = f[b[0][i]][0];
        for(j = 0; j < m; j++)
            c[i][j] = a[x][j];
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            cout << c[i][j] << " ";
        }
        cout << "\n";
    }
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
