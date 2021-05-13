#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
const int N = 4e5;
int len, pref[N];

int cnt(int a) {
    int c = a/len;
    int rem = a%len;
    return (c*pref[len] + pref[rem]);
}

int query(int l, int r) {
    return cnt(r) - cnt(l-1);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int a,b,q,i,j;
    cin >> a >> b >> q;
    len = a*b;
    for(i=1; i<=len; i++) {
        pref[i] = pref[i-1];
        if((i%a)%b != (i%b)%a)
            pref[i]++;
    }
    while(q--) {
        int l,r; cin >> l >> r;
        cout << query(l, r) << " ";
    }
    cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
