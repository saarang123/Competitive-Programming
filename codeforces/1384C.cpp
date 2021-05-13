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

const int N = 1e5+2;
string a,b;
set<int> st[22];
void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    for(int i=0; i<20; i++) st[i].clear();
    cin >> n;
    cin >> a >> b;
    for(int i=0; i<n; i++) {
        if(b[i] < a[i]) {
            return void(cout << -1 << "\n");
        }
        if(a[i]!=b[i]) st[a[i]-'a'].insert(b[i]-'a');
    }
    int ans = 0;
    for(i=0; i<20; i++) {
        if(!st[i].size()) continue;
        bool fst = true;
        int nxt;
        for(int v: st[i]) {
            if(fst) {
                ans++;
                nxt = v;
                fst = false;
                continue;
            }
            st[nxt].insert(v);
        }
    }
    cout << ans << "\n";
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
