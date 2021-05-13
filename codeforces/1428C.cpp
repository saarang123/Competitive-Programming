#include <bits/stdc++.h>
using namespace std;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int n = s.size(), ans = 0, c = 0;
        reverse(s.begin(), s.end());
        for(int i = 0; i < n; i++) {
            ans += (s[i] == 'B');
            if(ans) ans -= (s[i] == 'A');
            else c++;
        }
        ans = ans % 2 + c;
        cout << ans << endl;
    }
    return 0;
}
