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

const int N = 2e5+2;
int a[N][2], n;
vector<int> f;

void dfs(int i, int nxt = -1) {
    f.pb(i);
    if(f.size() == n)
        return;
    if(nxt != -1) {
        return void(dfs(nxt));
    }
    if(a[a[i][0]][0] == a[i][1] || a[a[i][0]][1] == a[i][1]) {
        return void(dfs(a[i][0], a[i][1]));
    }
    if(a[a[i][1]][0] == a[i][0] || a[a[i][1]][1] == a[i][0]) {
        return void(dfs(a[i][1], a[i][0]));
    }
    cout << -1 << "\n";
    exit(0);
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int i,j;
    cin >> n;
    for(i=1; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    dfs(1);
    for(auto v: f) cout << v << " "; cout << "\n";
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
