#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n; cin >> n;
    vector<int> a(n), c(n);
    for(int i = 0; i < n; i++)
        cin >> a[i], c[i] = a[i];
    sort(c.begin(), c.end());
    int mn = n + 1, mx = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == c[i]) continue;
        mn = min(mn, i);
        mx = i;
    }
    if(mx == -1)
        return cout << "yes\n 1 1\n", 0;
    int j = mn;
    for(int i = mx; i >= mn; i--) {
        if(a[i] != c[j++])
            return cout << "no\n", 0;
    }
    cout << "yes\n" << mn + 1 << " " << mx + 1<< "\n";
    return 0;
}
