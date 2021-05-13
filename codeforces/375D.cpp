#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;

#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define f first
#define ss second

template<class T> bool remin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool remax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

inline int scan(){
    char c = getchar();
    int x = 0;
    while(c<'0'||c>'9'){
            c=getchar();
        }
    while(c>='0'&&c<='9'){
            x=(x<<1)+(x<<3)+c-'0';
            c=getchar();
        }
    return x;
}

const int N = 1e5+3;
vector<int> g[N];
int c[N], ans[N];
vector<pair<int,int>> q[N];
map<int, int> ok[N];
ordered_set cnt[N];

void dfs(int v, int p) {
    pair<int, int> id = mp(-1,-1);
    for(int u: g[v]) {
        if(u==p) continue;
        dfs(u, v);
        remax(id, mp((int) cnt[u].size(), u));
    }
    if(id.ss!=-1) {
        cnt[v].swap(cnt[id.ss]);
        ok[v].swap(ok[id.ss]);
    }
    for(int u: g[v]) {
        if(u==p || u==id.ss) continue;
        for(auto x: cnt[u]) {
            cnt[v].erase(mp(ok[v][x.ss], x.ss));
            ok[v][x.ss] += x.f;
            cnt[v].insert(mp(ok[v][x.ss], x.ss));
        }
    }
    cnt[v].erase(mp(ok[v][c[v]], c[v]));
    ok[v][c[v]]++;
    cnt[v].insert(mp(ok[v][c[v]], c[v]));
    //cout << v << ": \n";
    //for(pair<int,int> u: cnt[v]) cout << u.ss << " " << u.f << "\n"; cout << "\n";
    for(auto qe: q[v]) {
        int k = qe.f, i = qe.ss;
        ans[i] = cnt[v].size() - cnt[v].order_of_key(mp(k,-1e9));
    }
}

void solve_case() {
    // :pray: :fishy: :orz:
    int n,m,i,j;
    n = scan(); m = scan();
    for(i=1; i<=n; i++) c[i] = scan();
    for(i=0; i<n-1; i++) {
        int v = scan();
        int u = scan();
        g[v].pb(u);
        g[u].pb(v);
    }
    for(i=1; i<=m; i++) {
        int v = scan();
        int k = scan();
        q[v].pb(mp(k,i));
    }
    dfs(1,-1);
    for(i=1; i<=m; i++) cout << ans[i] << "\n";
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
