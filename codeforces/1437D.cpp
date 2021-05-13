#include <bits/stdc++.h>

void solve_case() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), h(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    int l = 1, r = 1;
    for(int i = 0; l < n && r < n && i < n; l = r, i++) {
        r++;
        while(r < n && a[r - 1] <= a[r]) r++;
        for(int j = l; j < r; j++)
            h[j] = h[i] + 1;
    }
    std::cout << h.back() << std::endl;
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
