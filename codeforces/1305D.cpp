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

const int N = 1003;
vector<int> g[N];
int deg[N];
bool f[N];
int ask(int v, int u) {
    cout << "? " << v << " " << u << endl;
    cout.flush();
    int w; cin >> w;
    assert(w!=-1);
    return w;
}

void ans(int a) {
    cout << "! " << a << endl;
    cout.flush();
    exit(0);
}

void solve_case() {
    // :pray: :fishy: :orz:
    int n,i,j;
    cin >> n;
    for(i=0; i<n-1; i++) {
        int v,u;
        cin >> v >> u;
        g[v].pb(u);
        g[u].pb(v);
        deg[v]++; deg[u]++;
    }
    while(true) {
        int u = -1, v = -1;
        for(i=1; i<=n; i++) if(deg[i]==1 && !f[i]) u = i;
        for(i=n; i; i--) if(deg[i]==1 && !f[i]) v = i;
        if(u==-1) {
            int w = -1;
            for(i=1; i<=n; i++) if(!f[i]) w = i;
            ans(w);
        }
        if(u==v) {
            ans(u);
        }
        int w = ask(u, v);
        if(w==u || w==v) {
            ans(w);
        }
        for(int k: g[u]) deg[k]--;
        for(int k: g[v]) deg[k]--;
        f[v] = f[u] = true;
    }
    cout << -1 << "\n";
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
