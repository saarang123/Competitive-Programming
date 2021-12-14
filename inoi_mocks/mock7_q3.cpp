#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    std::cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}

void solve_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    vector<int> a;
    for(int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    if(n > 2)
    	cout << -1 << '\n';
    else if(n == 1)
    	cout << 1 << ' ' << k << ' ' << 0 << ' ' << 0 << '\n';
    else
    	cout << 1 << ' ' << b[0] << ' ' << 2 << ' ' << b[1] << '\n';
}
