#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define double long double
#define f first
#define ss second
#define mp make_pair
#define pb push_back

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 1e5+3;
vii graph(N);
ll a[N];
int vis[N] = {0};
vi cc;

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = 1;
    cc.pb(v);
    for(int u: graph[v])
    {
        //int u = graph[v][i];
        dfs(u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,n) cin >> a[i];
    RE(i,n) vis[i] = 0;
    RE(i,m)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    ll ans=0;
    RE(i,n)
    {
        cc.clear();
        ll pres = 1e16;
        dfs(i);
        if(cc.empty()) continue;
        for(int j: cc) pres = min(pres,a[j]);
        ans+=pres;
    }
    cout << ans << "\n";
    return 0;
}
