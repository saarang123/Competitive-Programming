#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    vector<int> a;
    vector<vector<int>> t;
    int n;

    void init(vector<int> a) {
        this -> a = a;
        n = (int) a.size();

        int k = lg(n);
        t.assign(n, vector<int> (k + 1));

        for (int i = 0; i < n; i++) {
            t[i][0] = i;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1<<j) <= n; i++) {
                t[i][j] = merge(t[i][j - 1], t[i + (1<<(j - 1))][j - 1]);
            }
        }
    }

    int merge(int x, int y) {
        if (a[x] >= a[y]) return x;
        else return y;
    }

    int lg(int x) {
        return 31 - __builtin_clz(x);
    }

    int query(int l, int r) {
        int j = lg(r - l + 1);
        return merge(t[l][j], t[r - (1<<j) + 1][j]);
    }
};

int main() {
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;

    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }

    SparseTable A;
    A.init(a);

    int m;
    cin >> m;

    pair<int, int> kl[m];
    for (int i = 0; i < m; i++) {
        cin >> kl[i].first >> kl[i].second;
    }

    int idx[m];
    iota(idx, idx + m, 0);
    sort(idx, idx + m, [&] (int &x, int &y) {return kl[x] < kl[y];});

    sort(kl, kl + m);

    set<pair<int, int>> t = {{0, n - 1}};
    vector<int> curr(n + 1, 0); // Ordered set (implemented using fenwick tree)

    int p = 0;
    int ans[m];

    for (int i = 1; i <= n; i++) {
        auto it = t.end();
        it--;
        pair<int, int> v = *it;

        int j = A.query(v.first, v.second);

        pair<int, int> b = {v.first, j - 1}, c = {j + 1, v.second};

        if (b.first <= b.second) t.insert(b);
        if (c.first <= c.second) t.insert(c);
        t.erase(v);

        for (int k = j + 1; k <= n; k += k & -k) {
            // Ordered set insert element
            curr[k]++;
        }

        while (p < m && i == kl[p].first) {
            // binary search
            int l = 0, r = n;

            while (l + 1 < r) {
                int mid = (l + r) / 2;

                int x = 0;
                for (int k = mid; k > 0; k -= k & -k) {
                    // Ordered set get kth
                    x += curr[k];
                }

                if (x < kl[p].second) l = mid;
                else r = mid;
            }

            ans[idx[p]] = a[l];
            p++;
        }
    }

    for (int u: ans) cout << u;
}