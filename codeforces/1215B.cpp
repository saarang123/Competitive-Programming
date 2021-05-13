#include <bits/stdc++.h>
using namespace std;


signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    string s, t;
    cin >> s >> t;
    int c[2] = {0, 0};
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        c[0] += (s[i] == 'a') + (t[i] == 'a');
        c[1] += (s[i] == 'b') + (t[i] == 'b');
        if(s[i] != t[i]) {
            if(s[i] == 'a') a.push_back(i);
            else b.push_back(i);
        }
    }
    if(c[0] & 1 || c[1] & 1)
        return cout << -1 << '\n', 0;
    vector<array<int, 2>> ans;
    for(int i = 0; i + 1 < a.size(); i += 2) {
        ans.push_back({a[i], a[i + 1]});
    }
    for(int i = 0; i + 1 < b.size(); i += 2) {
        ans.push_back({b[i], b[i + 1]});
    }
    if(a.size() & 1) {
        ans.push_back({a.back(), a.back()});
        ans.push_back({a.back(), b.back()});
    }
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x[0] + 1 << ' ' << x[1] + 1 << '\n';
    return 0;
}
