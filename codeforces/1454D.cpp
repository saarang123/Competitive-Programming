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

#define int long long
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j;
    cin >> n;
    map<int, int> cnt;
    int x = n, ok = sqrt(n + 2);
    for(int i = 2; i * i <= n; i++) {
        if(x % i) continue;
        while(x % i == 0) {
            cnt[i]++;
            x /= i;
        }
    }
    if(x > 1) cnt[x]++;
    array<int, 2> ans = {0, 0};
    for(auto c : cnt) {
        if(remax(ans[0], c.second))
            ans[1] = c.first;
    }
    cout << ans[0] << '\n';
    int p = 1;
    for(int i = 0; i < ans[0] - 1; i++) { cout << ans[1] << ' '; p *= ans[1]; }
    cout << (n / p) << '\n';
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
