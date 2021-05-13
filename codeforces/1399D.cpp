#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve_case() {
    int n,i,j;
    cin >> n;
    string s; cin >> s;
    s =  " " + s;
    set<int> ok[2];
    int f[n+2];
    for(i=1; i<=n; i++) {
        f[i] = 0;
        if(s[i]=='0') ok[0].insert(i);
        else ok[1].insert(i);
    }
    i = 0, j=0;
    int na = ok[0].size(), nb = ok[1].size(), cnt=1;
    while(ok[0].size() && ok[1].size()) {
        int id = min(*ok[0].begin(), *ok[1].begin());
        int tx = 0;
        if(s[id]=='1') tx = 1;
        ok[tx].erase(id);
        f[id] = cnt;
        while(id<n) {
            tx ^= 1;
            auto it = ok[tx].lower_bound(id);
            if(it==ok[tx].end()) break;
            f[*it] = cnt;
            id = *it;
            ok[tx].erase(it);
        }
        cnt++;
    }

    for(i=0; i<2; i++) {
        while(ok[i].size()) {
            f[*ok[i].begin()] = cnt++;
            ok[i].erase(ok[i].begin());
        }
    }
    cout << cnt-1 << "\n";
    for(i=1; i<=n; i++) cout << f[i] << " \n"[i==n];
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
