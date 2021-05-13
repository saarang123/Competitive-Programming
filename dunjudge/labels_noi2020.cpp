#include <bits/stdc++.h>
using namespace std;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> d(n, -1), a(n);
    for(int i = 1; i < n; i++) cin >> d[i];
    int max_id = 0, min_id = 0;
    a[0] = 1;
    for(int i = 1; i < n; i++) {
        a[i] = d[i] + a[i - 1];
        if(a[i] > a[max_id]) max_id = i;
        if(a[i] < a[min_id]) min_id = i;
    }
    auto left = [&] (int x) {
        for(int i = x - 1; i >= 0; i--)
                a[i] = a[i + 1] - d[i + 1];
    };
    auto right = [&] (int x) {
        for(int i = x + 1; i < n; i++)
            a[i] = d[i] + a[i - 1];
    };
    a[max_id] = n;
    left(max_id); right(max_id);
    if(a[min_id] > 1) cout << -1 << '\n';
    else {
        for(int i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
    }
    return 0;
}
