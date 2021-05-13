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

const int N = 5003;
int a[N][N], f[N];
vector<int> g[N];
void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,q;
    cin >> n >> q;
    for(i=1; i<=q; i++) {
        int l,r;
        cin >> l >> r;
        for(int k=l; k<=r; k++) {
            g[k].pb(i);
        }
    }
    int cnt = 0;
    for(i=1; i<=n; i++) {
        if(g[i].size() == 1) {
            f[g[i][0]]++;
        }
        else if(g[i].size() == 2) {
            a[g[i][0]][g[i][1]]++;
            a[g[i][1]][g[i][0]]++;
        }
        if(g[i].size())
            cnt++;
    }
    int ans = -1;
    for(i=1; i<=q; i++) {
        for(j=i+1; j<=q; j++) {
            remax(ans, cnt - f[i] - f[j] - a[i][j]);
        }
    }
    cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
