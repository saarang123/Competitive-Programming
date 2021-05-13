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

#define int long long
const int N = 1e5+2;
int n,i,j,s, dt[N], c[N], wt[N], ok[N];
vector<pair<int, pair<int, int>>> g[N];
vector<int> one, two;
auto gain = [&](int u, int w) { return (w + 1) / 2 * c[u]; };

void dfs(int v, int p, int d) {
    c[v] = (g[v].size()==1);
    dt[v] = d;
    for(auto pa: g[v]) {
        int u = pa.f, w = pa.ss.f, q = pa.ss.ss;
        if(u==p) continue;
        dfs(u, v, d+w);
        c[v] += c[u];
        while(w) {
            if(q==1) one.pb(gain(u, w));
            else two.pb(gain(u, w));
            w /= 2;
        }
    }
}

void solve_case() {
    cin >> n >> s;
    for(i=1; i<=n; i++) {
        g[i].clear();
        dt[i] = 0;
        c[i] = 0;
    }
    for(i=2; i<=n; i++) {
        int v,u,w, c;
        cin >> v >> u >> w >> c;
        g[v].pb(mp(u, mp(w, c)));
        g[u].pb(mp(v, mp(w, c)));
    }
    dfs(1,-1,0);
    sort(all(one)); sort(all(two));
    one.pb(0); two.pb(0);
    reverse(all(one)); reverse(all(two));
    for(i=1; i<one.size(); i++) one[i] += one[i-1];
    for(i=1; i<two.size(); i++) two[i] += two[i-1];
    int sum = 0;
    for(i=1; i<=n; i++) if(g[i].size()==1) sum += dt[i];
    int ans = 1e9;
    if(sum<s) {
        return void(cout << 0 << "\n");
    }
    for(i=0; i<one.size(); i++) {
        j = lower_bound(all(two), sum-one[i]-s) - two.begin();
        if(j!=two.size()) remin(ans,i+2*j);
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
