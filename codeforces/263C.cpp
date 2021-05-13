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
int vis[N], ans[N] ,n;

bool can(int a, int b)
{
    if(a==0 || b==0) return true;
    REP(i,0,3) if(graph[a][i]==b) return true;
    return false;
}

void dfs(int v)
{
    if(v==n)
    {
        if(!can(ans[n],ans[1]) || !can(ans[n],ans[2]) || !can(ans[n-1], ans[1])) return;
        RE(i,n) cout << ans[i] << " "; cout << "\n";
        exit(0);
    }
    REP(i,0,3)
    {
        ans[v+1] = graph[ans[v]][i];
        if(!can(ans[v-1],ans[v+1]) || vis[ans[v+1]]) continue;
        vis[ans[v+1]] = 1;
        dfs(v+1);
        vis[ans[v+1]] = 0;
    }
}

void solve_case()
{
    int i,j,t,k,m;
    cin >> n;
    RE(i,2*n)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    RE(i,n)
    {
        if(graph[i].size()!=4)
        {
            cout << -1 << "\n";
            exit(0);
        }
    }
    ans[1] = 1;
    vis[1] = 1;
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
        cout << -1 << "\n";
    }
    return 0;
}
