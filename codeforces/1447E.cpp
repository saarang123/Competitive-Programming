#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(vector<int> &a, int bit) {
    if(a.size() <= 2) return 0;
    if(bit < 0) return 0;
    vector<int> on, off;
    for(int x : a) {
        if(x & (1LL << bit)) on.push_back(x); //on connects with on
        else off.push_back(x); //off with off
    }
    if(on.empty()) return f(off, bit - 1);
    if(off.empty()) return f(on, bit - 1);
    return min(on.size() - 1 + f(off, bit - 1), off.size() - 1 + f(on, bit - 1)); //no edges b/w on and off
}

void solve_case() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    cout << f(a, 31) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve_case();
    }
    return 0;
}
