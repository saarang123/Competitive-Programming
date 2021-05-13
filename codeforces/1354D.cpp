#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int tree[N], n;

void upd(int x, int v = 1) {
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
    #ifndef ONLINE_JUDGE
            freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
            freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    int q; cin >> n >> q;
    for(int i = 0, x; i < n; i++) {
        cin >> x; upd(x);
    }
    for(int i = 0, k; i < q; i++) {
        cin >> k;
        if(k > 0) upd(k);
        else {
            k = abs(k);
            int mn = 1, mx = n, id = -1;
            while(mn < mx) {
                int mid = (mn + mx) >> 1;
                int x = qry(mid);
                //cout << mn << ' ' << mid << ' ' << mx << ' ' << x << endl;
                if(x >= k) mx = mid, id = mx;
                else mn = mid + 1;
            }
            id = mn;
            upd(id, -1);
        }
    }
    for(int i = 1; i <= n; i++) if(qry(i, i)) return cout << i << '\n', 0;
    cout << 0 << '\n';
    return 0;
}
