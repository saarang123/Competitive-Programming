#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll cnt = 1;
    for(int i = 0; i < n; i++) {
        cnt *= 2;
        if(cnt > m) break;
    }
    cout << m % cnt << endl;
    return 0;
}
