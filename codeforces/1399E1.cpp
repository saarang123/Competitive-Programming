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
int n,i,j,s, dt[N], c[N], ok[N];
vector<pair<int, int>> g[N];
priority_queue<pair<int,pair<int,int>>> pq;

void dfs(int v, int pa, int d) {
    dt[v] = d;
    c[v] = (v!=1 && g[v].size()==1);
    for(auto p: g[v]) {
        int u = p.f, w = p.ss;
        if(u==pa) continue;
        dfs(u, v, w+d);
        c[v] += c[u];
    }
}

void fix(int v, int pa) {
    for(auto p: g[v]) {
        int u = p.f, w = p.ss;
        if(u==pa) continue;
        ok[u] = (w+1)/2;
        fix(u,v);
        pq.push(mp((w-w/2)*c[u], mp(w, c[u])));
    }
}

void solve_case() {
    cin >> n >> s;
    for(i=1; i<=n; i++) {
        g[i].clear();
        dt[i] = 0;
        c[i] = 0;
    }
    for(i=0; i<n-1; i++) {
        int v,u,w;
        cin >> v >> u >> w;
        g[v].pb(mp(u,w));
        g[u].pb(mp(v,w));
    }
    dfs(1,-1,0);
    //for(i=1; i<=n; i++) cout << dt[i] << " \n"[i==n];
    //for(i=1; i<=n; i++) cout << c[i] << " \n"[i==n];
    int d = 0;
    for(i=1; i<=n; i++) if(g[i].size()==1) d += dt[i];
    fix(1,-1);
    int ans = 0;
    while(d>s) {
        auto p = pq.top(); pq.pop();
        int w = p.ss.f, l = p.ss.ss;
        d -= p.first;
        w/=2;
        pq.push(mp((w-w/2)*l, mp(w,l)));
        ans++;
    }
    while(!pq.empty()) pq.pop();
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
