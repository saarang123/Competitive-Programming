#include <bits/stdc++.h>
using namespace std;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool f[] = {0, 0};
        vector<bool> g(n);
        for(int i = 0; i < n; i++) {
            f[0] |= (s[i] == '>');
            f[1] |= (s[i] == '<');
            if(s[i] == '-') g[i] = g[(i + 1) % n] = true;
        }
        int ans = 0;
        for(bool x : g) ans += x;
        if(!f[0] || !f[1]) ans = n;
        cout << ans << endl;
    }
    return 0;
}
