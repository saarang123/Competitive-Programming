#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<typename T>
istream& operator >> (istream& is, vector<T> &a) { for(T &element : a) is >> element; return is; }


void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m, -1));
    vector<multiset<int>> s(n);
    vector<array<int, 3>> c;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            s[i].insert(a[i][j]);
            c.push_back({a[i][j], i, j});
        }
    sort(c.begin(), c.end());
    for(int i = 0; i < m; i++) {
        b[c[i][1]][i] = c[i][0];
        s[c[i][1]].erase(s[c[i][1]].find(c[i][0]));
    }
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) if(b[i][j] == -1) {
            b[i][j] = *s[i].begin();
            s[i].erase(s[i].begin());
        }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << b[i][j] << ' ';
        cout << '\n';
    }
}
