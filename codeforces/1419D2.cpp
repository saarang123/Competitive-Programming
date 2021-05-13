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
    int n,i,j;
    cin >> n;
    vector<int> a(n), v(n, -1);
    for(int &x: a)
        cin >> x;
    sort(all(a));
    int id = 0;
    for(i = 1; i < n; i += 2)
        v[i] = a[id++];
    for(i = 0; i < n; i += 2)
        v[i] = a[id++];
    int ans = 0;
    for(i = 1; i < n - 1; i++)
        ans += (v[i] < v[i - 1] && v[i] < v[i + 1]);
    cout << ans << "\n";
    for(int x: v) cout << x << " "; cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
