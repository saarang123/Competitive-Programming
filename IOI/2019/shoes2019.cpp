#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int N = 2e5 + 2;
ll tree[N], n;
queue<int> l[N], r[N];

void upd(int x, int val) {
    for(; x <= n; x += (x & -x))
        tree[x] += val;
}

int sum(int x) {
    int ans = 0;
    for(; x > 0; x -= (x & -x))
        ans += tree[x];
    return ans;
}

int qry(int l, int r) { return sum(r) - sum(l - 1); };

long long count_swaps(vector<int> a) {
    n = a.size(); int i, j;
    for(i = 0; i < n; i++) {
        if(a[i] > 0) l[a[i]].push(i + 1);
        else r[-a[i]].push(i + 1);
    }
    ll ans = 0;
    for(i = 0; i < n; i++) {
        if(a[i] > 0) {
            if(l[a[i]].front() != i + 1) continue;
            l[a[i]].pop();
            int id = r[a[i]].front(); r[a[i]].pop();
            ans += (id - i - 1 - qry(i + 1, id));
            //cout << i << " " << a[i] << " " << id - i - qry(i + 1, id) << endl;
            upd(id, 1);
        }
        else {
            if(r[-a[i]].front() != i + 1) continue;
            r[-a[i]].pop();
            int id = l[-a[i]].front(); l[-a[i]].pop();
            ans += (id - i - 2 - qry(i + 1, id));
            //cout << i << " " << a[i] << " " << id - i - 1 - qry(i + 1, id) << endl;
            upd(id, 1);
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);
    int i,j;
    cin >> n;
    vector<int> a(2 * n);
    for(auto &x : a) cin >> x;
    cout << count_swaps(a) << endl;
    return 0;
}
