#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
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
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e9;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 1e5+5;
vi graph[N];
int tin[N], ans[N], k, visit[N];

void dfs(int p)
{
    int v = ans[p];
    visit[v] = 1;
    REP(i, 0, graph[v].size()-1)
    {
        int u = graph[v][i];
        if(visit[u])
        {
            if(p-tin[u]+1>k)
            {
                cout << p-tin[u]+1 << "\n";
                REP(i,tin[u],p) cout << ans[i] << " "; cout << "\n";
                exit(0);
            }
            else continue;
        }
        else
        {
            ans[p+1] = u;
            tin[u] = p+1;
            dfs(p+1);
            tin[u] = 0;
        }
    }
}

void solve_case()
{
    int n,i,j,t,m;
    cin >> n >> m >> k;
    RE(t,m)
    {
        cin >> i >> j;
        graph[i].pb(j);
        graph[j].pb(i);
    }
    ans[1] = 1;
    tin[1] = 1;
    dfs(1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int T = 1;
    //cin >> T;
    while(T--)
    {
        solve_case();
    }
    return 0;
}
