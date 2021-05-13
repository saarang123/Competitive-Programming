#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 2;

int t[2][32];

void f(vector<int> &a, int bit) {
    vector<int> on, off;
    int oz = 0, zo = 0, one = 0, zero = 0;
    for(int x : a) {
        if(x >> bit & 1) {
            one++;
            zo += zero;
            on.push_back(x);
        } else {
            zero++;
            oz += one;
            off.push_back(x);
        }
    }
    t[0][bit] += oz;  //one --> zero inversion
    t[1][bit] += zo;  //zero --> one inversion
    if(bit) {
        if(on.size()) f(on, bit - 1);
        if(off.size()) f(off, bit - 1);
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    f(a, 30);
    int x = 0, inv = 0;
    for(int i = 30; i >= 0; i--) {
        if(t[1][i] < t[0][i]) {
            inv += t[1][i];
            x ^= (1 << i);
        } else {
            inv += t[0][i];
        }
    }
    cout << inv << ' ' << x << '\n';
    return 0;
}
