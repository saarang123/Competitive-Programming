#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 150000 + 2;
const ld eps = 1e-8;
void solve_case() {
    int n, x;
    cin >> n >> x;
    string s; cin >> s;
    int cnt = 0;
    for(char c : s) {
        cnt -= (c == '1');
        cnt += (c == '0');
    }
    int ans = (x == 0), t = 0;
    for(int i = 0; i < n; i++) {
        t += (s[i] == '0');
        t -= (s[i] == '1');
        if(cnt == 0) {
            if(t == x) return void(cout << -1 << '\n');
            continue;
        }
        int j = (x - t) / cnt;
        if((t + j * cnt) == x && j >= 0) {
            ans++;
        }
    }
    cout << ans << '\n';
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
