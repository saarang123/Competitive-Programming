#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const string op[] = {"AND", "OR", "XOR"};
const int N = (1 << 16) + 3;
int p[N], a[N];

int query(int id, int i, int j) {
    cout << op[id] << ' ' << i << ' ' << j << '\n';
    cout.flush();
    int x; cin >> x;
    return x;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
        p[i] = query(2, 1, i);
    }
    int ab = p[2] + 2 * query(0, 1, 2);
    int bc = (p[2] ^ p[3]) + 2 * query(0, 2, 3);
    int ca = p[3] + 2 * query(0, 1, 3);
    a[1] = (ab + ca - bc) / 2;
    a[2] = (bc + ab - ca) / 2;
    a[3] = (ca + bc - ab) / 2;
    cout << "! " << a[1] << ' ' << a[2] << ' ' << a[3] << ' ';
    for(int i = 4; i <= n; i++) cout << (p[i] ^ a[1]) << ' '; cout << '\n';
    return 0;
}
