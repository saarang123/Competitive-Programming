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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n, m;
    cin >> n >> m;
    int id = -1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        if(i != x) id = i;
    }
    ld ans = 1;
    while(m--) {
        int x; cin >> x; x--;
        ld p; cin >> p;
        if(x >= id) ans *= (1 - p);
    }
    if(id == -1) cout << 1 << '\n';
    else cout << setprecision(10) << 1 - ans << '\n';
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
