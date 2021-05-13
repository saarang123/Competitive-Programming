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
    auto out = [&] (vector<bool> o) {
        for(auto bo : o) cout << (bo ? '(' : ')');
        cout << '\n';
    };
    int n; cin >> n;
    string s; cin >> s;
    int cnt[] = {0, 0};
    vector<int> ok[2];
    for(auto c : s) cnt[c - '0']++;
    if(s[0] != '1' || s.back() != '1' || cnt[1] % 2)
        return void(cout << "NO" << '\n');
        
    for(int i = 0; i < n; i++) 
        ok[s[i] - '0'].push_back(i);
    vector<bool> a(n), b(n);;
    for(int c = 0, i = 0; i < n; i++) {
        if(s[i] == '0') {
            a[i] = 1, b[i] = 0;
            if(c & 1) swap(a[i], b[i]);
            c++;
        }
    }
    for(int i = 0, j = ok[1].size() - 1; i < j; i++, j--) {
        a[ok[1][i]] = b[ok[1][i]] = 1;
        a[ok[1][j]] = b[ok[1][j]] = 0; 
    }
    cout << "YES" << '\n';
    out(a); out(b);
}
