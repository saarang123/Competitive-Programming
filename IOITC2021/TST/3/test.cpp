#include <bits/stdc++.h>
using namespace std;
//#define int long long
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n, x[2];
    cin >> n >> x[0] >> x[1];
    vector<int> a(n);
    for(int &xx : a)
        cin >> xx;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        vector<int> c[2];
        for(int i = 0; i < n; i++)
            c[mask >> i & 1].push_back(i);
        bool flag = 1;
        for(int j = 0; j < 2 && flag; j++)
        for(int i = 1; i < c[j].size() && flag; i++) 
            if(abs(a[c[j][i]] - a[c[j][i - 1]]) < x[j])
                flag = 0;
        ans += flag;
        if(ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
    return 0;
}