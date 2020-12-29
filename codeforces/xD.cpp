#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << " :: " << #x << " " << x << "\n";
#define int long long

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int m1 = 2e9, m2 = 2e9, m3 = 2e9, sum = 0;
    for(int i = 0; i < n1; i++) {
        int x; cin >> x;
        sum += x; m1 = min(m1, x);
    }
    for(int i = 0; i < n2; i++) {
        int x; cin >> x;
        sum += x; m2 = min(m2, x);
    }
    for(int i = 0; i < n3; i++) {
        int x; cin >> x;
        sum += x; m3 = min(m3, x);
    }
    int ans = max(sum - 2 * (m1 + m2), sum - 2 * (m2 + m3));
    ans = max(ans, sum - 2 * (m3 + m1));
    cout << ans << '\n';
    return 0;
}
