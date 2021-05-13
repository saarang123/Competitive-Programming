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

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,x;
    string s;
    cin >> s >> x;
    n = s.size();
    int a[n+2];
    for(i=0; i<=n; i++) a[i] = -1;
    s = " " + s;
    auto in = [&](int i) {
        return (i>0 && i<=n);
    };
    for(i=1; i<=n; i++) {
        if(s[i]=='1') continue;
        if(in(i-x)) a[i-x] = 0;
        if(in(i+x)) a[i+x] = 0;
    }
    for(i=1; i<=n; i++) if(a[i]==-1) a[i] = 1;
    for(i=1; i<=n; i++) {
        if(s[i]=='0') continue;
        int pos = 0;
        if(in(i-x)) pos |= a[i-x];
        if(in(i+x)) pos |= a[i+x];
        if(!pos) {
            cout << -1 << "\n";
            return;
        }
    }
    for(i=1; i<=n; i++) cout << a[i];cout << "\n";
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
