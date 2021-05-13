#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 2, M = 1e6 + 2;
int tree[N], a[N], d[M], n;

void upd(int x, int v) {
    for(; x <= n; x += (x & -x))
        tree[x] += v;
}

int qry(int x) {
    int ans = 0;
    for(; x > 0; x -= (x & -x))
        ans += tree[x];
    return ans;
}

int qry(int l, int r) { return qry(r) - qry(l - 1); }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    for(int i = 1; i < M; i++) {
        for(int j = 1; j * i < M; j++)
            d[j * i]++;
    }
    int m;
    cin >> n >> m;
    set<int> st;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i, a[i]);
        if(a[i] > 2) st.insert(i);
    }
    st.insert(n + 1);
    while(m--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1) {
            for(auto i = *st.lower_bound(l); i <= r; i = *st.upper_bound(i)) {
                upd(i, -a[i]);
                a[i] = d[a[i]];
                upd(i, a[i]);
                if(a[i] <= 2) st.erase(i);
            }
        } else {
            cout << qry(l, r) << '\n';
        }
    }
    return 0;
}
