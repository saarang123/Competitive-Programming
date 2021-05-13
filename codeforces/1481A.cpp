#include <bits/stdc++.h>
using namespace std;
using ld = long double;
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
    int x, y;
    cin >> x >> y;
    vector<int> cnt(4);
    string s; cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') cnt[0]++;
        else if(s[i] == 'D') cnt[1]++;
        else if(s[i] == 'L') cnt[2]++;
        else cnt[3]++;
    }
    bool ok1 = false, ok2 = false;
    if(y < 0 && cnt[1] >= abs(y))
        ok1 = true;
    else if(y >= 0 && cnt[0] >= y)
        ok1 = true;
    if(x < 0 && cnt[2] >= abs(x))
        ok2 = true;
    else if(x >= 0 && cnt[3] >= x)
        ok2 = true;
    cout << ((ok1 && ok2) ? "YES" : "NO") << '\n';
}
