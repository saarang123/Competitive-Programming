#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 2, LGN = 30;
int t[N * LGN][2], c[N * LGN], tx = 1;

void insert(int x, int v = 1, int bit = LGN) {
    if(bit == -1) return void(c[v]++);
    auto child = (x >> bit & 1);
    if(t[v][child] == 0)
        t[v][child] = ++tx;
    insert(x, t[v][child], bit - 1);
}

bool remove(int x, int v = 1, int bit = LGN) {
    if(bit == -1) return --c[v] == 0;
    bool nxt = (x >> bit & 1);
    if(remove(x, t[v][nxt], bit - 1))
        t[v][nxt] = 0;
    return !(t[v][0] | t[v][1]);
}

int query(int x, int v = 1, int bit = LGN) {
    if(bit == -1) return x;
    bool nxt = (x >> bit & 1) ^ 1;
    if(t[v][nxt])
        return query(x ^ ((1 << bit) * nxt), t[v][nxt], bit - 1);
    return query(x ^ ((1 << bit) * (nxt ^ 1)), t[v][nxt ^ 1], bit - 1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int q; cin >> q;
    insert(0);
    while(q--) {
        char c; cin >> c;
        int x; cin >> x;
        if(c == '+') insert(x);
        else if(c == '-') remove(x);
        else cout << query(x) << '\n';
    }
    return 0;
}
