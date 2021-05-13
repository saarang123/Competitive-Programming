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

const int N = 5e5+2;
int t[4*N], g[4*N], tin[N], tout[N], tx = 1;
vector<int> adj[N];

void dfs(int v, int p) {
    tin[v] = tx++;
    for(int u: adj[v]) {
        if(u==p) continue;
        dfs(u, v);
    }
    tout[v] = tx-1;
}

void add(int v, int tl, int tr, int l, int r, int i) {
    if(l>r) return;
    if(tl>=l && tr<=r)
        return void(t[v] = i);
    int tm = (tl+tr)>>1;
    add(v<<1, tl, tm, l, min(tm,r), i);
    add((v<<1)|1, tm+1, tr, max(tm+1,l), r, i);
}


int get(int v, int tl, int tr, int pos) {
    if(tl==tr)
        return t[v];
    int tm = (tl+tr)>>1;
    if(pos<=tm)
        return max(t[v], get(v<<1, tl, tm, pos));
    return max(t[v], get((v<<1)|1, tm+1, tr, pos));
}

void upd(int v, int tl, int tr, int pos, int i) {
    if(tl==tr)
        return void(g[v] = i);
    int tm = (tl+tr)>>1;
    if(pos<=tm) upd((v<<1), tl, tm, pos, i);
    else upd((v<<1)|1, tm+1, tr, pos, i);
    g[v] = max(g[v<<1], g[(v<<1)|1]);
}

int query(int v, int tl, int tr, int l, int r) {
    if(l>r) return -1e9;
    if(tl>=l && tr<=r)
        return g[v];
    int tm = (tl+tr)>>1;
    return max(query(v<<1, tl, tm, l, min(tm, r)), query((v<<1)|1, tm+1, tr, max(tm+1, l), r));
}

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    cin >> n;
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    dfs(1, -1);
    //for(i=1; i<=n; i++) cout << tin[i] << " \n"[i==n];
    //for(i=1; i<=n; i++) cout << tout[i] << " \n"[i==n]; cout << "\n";
    int q; cin >> q;
    for(j=1; j<=q; j++) {
        int c,v;
        cin >> c >> v;
        if(c==1)
            add(1, 1, n, tin[v], tout[v], j);
        else if(c==2)
            upd(1, 1, n, tin[v], j);
        else {
            int q1 = get(1, 1, n, tin[v]);
            int q2 = query(1, 1, n, tin[v], tout[v]);
            cout << (q1>q2) << '\n';
        }
        //for(i=1; i<=n; i++) cout << get(1, 1, n, tin[i]) << " \n"[i==n];
        //for(i=1; i<=n; i++) cout << query(1, 1, n, tin[i], tin[i]) << " \n"[i==n]; cout << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int Testcases = 1;
    //std::cin >> Testcases;
    while(Testcases--) {
        solve_case();
    }
    return 0;
}
