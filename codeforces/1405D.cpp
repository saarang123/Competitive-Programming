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

const int N = 1e5+2;
vector<int> g[N];
int dt[N], p[N];

pair<int, int> dfs(int v, int par, int d)
{
    p[v] = par;
    dt[v] = d;
    pair<int, int> ret = mp(d,v);
    for(int u: g[v])
    {
        if(u==par) continue;
        ret = max(ret, dfs(u, v, d+1));
    }
    return ret;
}

void solve_case() {
    //check dp before greedy, loops, variables in loops, max N values etc.
    int n,i,j,a,b,da,db;
    cin >> n;
    for(i=0; i<=n; i++) {
        dt[i] = 0;
        p[i] = -1;
        g[i].clear();
    }
    cin >> a >> b >> da >> db;
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        g[v].pb(u); g[u].pb(v);
    }
    pair<int, int> ds = dfs(a, -1, 0);
    if(dt[b] <= da) {
        return void(cout << "Alice\n"); //one move
    }
    ds = dfs(ds.second, -1, 0);
    if(2*da >= ds.first) {
        return void(cout << "Alice\n");  //go to center
    }
    if(db > 2*da) {
        return void(cout << "Bob\n");
    }
    cout << "Alice\n";
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
