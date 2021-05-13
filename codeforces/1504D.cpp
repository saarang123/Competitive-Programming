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


void solve_case() {
    int n; cin >> n;
    vector<vector<int>> a(n + 2, vector<int> (n + 2, -1));
    auto qry = [&] (int c, int i, int j) {
        cout << c << ' ' << i + 1 << ' ' << j + 1 << endl;
        cout.flush();
        a[i][j] = c;
    };
    auto find = [&] (int c) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) if(a[i][j] < 0 && (i + j) % 2 == c) return make_pair(i, j);
        return make_pair(-1, -1);
    };
    for(int turn = 0; turn < n * n; turn++) {
        int c; cin >> c;
        if(c == 1) {
            auto [i, j] = find(0);
            if(i < 0) {
                auto [ii, ji] = find(1);
                assert(0 <= ii < n);
                qry(3, ii, ji);
            } else 
                qry(2, i, j);
        } else if(c == 2) {
            auto [i, j] = find(1);
            if(i < 0) {
                auto [ii, ji] = find(0);
                assert(0 <= ii < n);
                qry(3, ii, ji);
            } else 
                qry(1, i, j);
        } else {
            auto [i, j] = find(0);
            if(i < 0) {
                auto [ii, ji] = find(1);
                assert(0 <= ii < n);
                qry(1, ii, ji);
            } else 
                qry(2, i, j);
        }
    }
}
