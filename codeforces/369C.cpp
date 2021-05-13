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
#define pll pair<ll,ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
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

const int N = 1e5+5;
vii graph(N);
map<pii, bool> edges;
set<int> sol;
int vis[N]={0};

void dfs(int v, int p, int last)
{
    if(vis[v]) return;
    vis[v] = 1;
    bool x = 0;
    if(edges[mp(v,p)])
    {
        sol.erase(last);
        sol.insert(v);
        x = 1;
    }
    for(int u: graph[v])
    {
        dfs(u,v, x==1 ? v:last);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(t,n-1)
    {
        cin >> i >> j >> k;
        graph[i].pb(j);
        graph[j].pb(i);
        edges[mp(i,j)] = k-1;
        edges[mp(j,i)] = k-1;
    }

    dfs(1,-1,-1);
    cout << sol.size() << "\n";
    print(sol);
    return 0;
}
