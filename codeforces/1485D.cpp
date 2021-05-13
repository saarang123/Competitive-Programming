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
    //std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

const int value = 720720;
void solve_case() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for(auto &row : a) 
        for(auto &x : row)
            cin >> x;
    auto f = [&] (int x) {
        return x * x * x * x;
    };
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) & 1)
                cout << value << ' ';
            else
                cout << value - f(a[i][j]) << ' ';
        }
        cout << '\n';
    }
}
