#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2002;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, p, mx = 0;
    cin >> n >> p;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
    sort(a.begin(), a.end());
    vector<int> ans;
    for(int x = mx - n + 1; x < mx; x++) {
        int cnt = 0, l = 0, r = 0;
        bool can = true;
        for(int t = x; t < x + n; t++) {
            while(r < n && a[r] <= t) r++; //new choices
            cnt += (r - l);
            l = r;
            if(cnt % p == 0) can = false; //cnt possible choices
            cnt--;  //chose one, x += 1
        }
        if(can) ans.push_back(x);
    }
    cout << ans.size() << endl;
    for(int x : ans) cout << x << " "; cout << endl;
    return 0;
}
