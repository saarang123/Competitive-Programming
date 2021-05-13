#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 1e5;
set<array<int, 2>> st;

int f(int x, int y) {
    return !st.count({x, y}) && !st.count({y, x});
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
    int i, j, n, m;
    cin >> n >> m;
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        st.insert({u, v});
        st.insert({v, u});
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(f(i, j) && f(j, k) && f(k, i))
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
