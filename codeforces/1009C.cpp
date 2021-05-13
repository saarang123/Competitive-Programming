#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

void solve_case() {
    int n, m;
    cin >> n >> m;
    int mn = 1e9, mx = 0;
    int s = 0;
    for(int i = 0; i < n; i++) s += i;
    mx = s, mn = s;
    int j = n - 1;
    for(int i = 1; i < n; i++) {
        s -= j--;
        s += i;
        mx = max(mx, s); mn = min(mn, s);
    }
    ld sum = 0;
    while(m--) {
        int x, d;
        cin >> x >> d;
        sum += x * n;
        if(d >= 1) sum += d * mx;
        else sum += d * mn;
    }
    ld ans = sum / (ld) n;
    cout << setprecision(10) << ans << '\n';
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
