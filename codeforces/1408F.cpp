#include <bits/stdc++.h>
using namespace std;
vector<array<int, 2>> ans;

void solve(vector<int> &a) {
    if(a.size() <= 1) return;
    vector<int> id[2];
    for(int i = 0; i < a.size(); i++)
        id[i & 1].push_back(a[i]);
    solve(id[0]);
    solve(id[1]);
    for(int i = 0; i < int(a.size()) / 2; i++)
        ans.push_back({id[0][i], id[1][i]});
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n; cin >> n;
    int p = 1;
    while (2 * p <= n) 
        p *= 2;
    vector<int> a(p);
    iota(a.begin(), a.end(), 1);
    solve(a);
    for(int i = 0; i < p; i++)
        a[i] = n - i;
    solve(a);
    cout << ans.size() << '\n';
    for(auto &[i, j] : ans)
        cout << i << ' ' << j << '\n';
    return 0;
}