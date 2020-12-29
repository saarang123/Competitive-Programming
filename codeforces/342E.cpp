#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
//#define int long long
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
const int INF = 1e8;
const int LGN = 20;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 1e5+5;
int sz[N], par[N], cnt=0, ans[N];
bool cent[N] = {0};
vi graph[N];
int t=18,sparse[N][LGN]={-1}; //Sparse table. sparse[n][i] gives the 2^ith parent of node n.
int depth[N];

//---------------------------------------LCA Begins-----------------------------------//

void dfs(int v, int p, int d) //Precomputation of sparse table and depth in O(n log n)
{
    depth[v] = d;
    sparse[v][0] = p;
    for(int i=1; i<=t; i++)
    {
        int pa = sparse[v][i-1];
        if(pa!=-1)
        {
            sparse[v][i] = sparse[pa][i-1];
        }
    }
    for(int i=0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p) continue;
        dfs(u,v,d+1);
    }
}

int find_kth(int a, int diff)  //O(log n)
{
    for(int i=0; i<=t; i++)      //Can also loop from T-1 to 0 if bottom thing used.
    {
        if((1<<i) & diff)        //or use if((1<<i) <= diff) k = k-2^i;
        {
            a = sparse[a][i];
        }
    }
    return a;
}

int lca(int a, int b)  //O(log n) per query
{
    //Ensures a,b are same depth
    if(depth[a]>depth[b])
    {
        a = find_kth(a, depth[a]-depth[b]);
    }
    else if(depth[b]>depth[a])
    {
        b = find_kth(b, depth[b]-depth[a]);
    }

    //If LCA(a,b) = a or b.
    if(a==b) return a;

    for(int i=t; i>=0; i--)
    {
        if(sparse[a][i]!=sparse[b][i])
        {
            a = sparse[a][i];
            b = sparse[b][i];
        }
    }
    return sparse[a][0];
}

int dist(int a, int b)
{
    return depth[a] + depth[b] - 2*depth[lca(a,b)];
}

//--------------------------------------------LCA Ends-----------------------------------------//

//-------------------------------Centroid Decomposition Begins----------------------------//


//Finding subtree sizes
void dfssz(int v, int p = -1)
{
    sz[v] = 1;
    for(int i = 0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p || cent[v]) continue;
        dfssz(u,v);
        sz[v] += sz[u];
    }
}

//Finds centroid of present subtree
int fcent(int v, int p = -1)
{
    for(int i = 0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p || cent[u]) continue;
        if(sz[u]  > cnt/2)
        {
            return fcent(u,v);
        }
    }
    return v;
}

//Decomposes the tree into the centroid tree.
void decompose(int v, int p = -1)
{
    dfssz(v);
    cnt = sz[v];
    int centroid = fcent(v);
    cent[centroid] = true;  //Notes which nodes are centroids.
    par[centroid] = p;     //Parents for centroid tree nodes array.
    for(int i = 0; i<graph[centroid].size(); i++)
    {
        int u = graph[centroid][i];
        if(u==p || cent[u]) continue;
        decompose(u,centroid);
    }
}

//-------------------------------Centroid Decomposition Ends----------------------------//


//------------------------------Querying Begins----------------------------------------//

void update(int v)
{
    int p = v;
    while(p!=-1)
    {
        ans[p] = min(ans[p], dist(p,v));
        p = par[p];
    }
}

int query(int v)
{
    int p = v, ret = INF;
    while(p!=-1)
    {
        ret = min(ret, ans[p] + dist(p,v));
        p = par[p];
    }
    return ret;
}

//--------------------------------Querying Ends--------------------------------------//

void solve_case()
{
    int n,i,j,q,k,m;
    cin >> n >> m;
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    dfs(1,-1,0);
    decompose(1);
    //RE(i,n) cout << par[i] << " "; cout << "\n";
    RE(i,n) ans[i] = INF;
    update(1);
    while(m--)
    {
        cin >> q >> k;
        if(q==1)
            update(k);
        else
            cout << query(k) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int TestCases = 1;
    //cin >> TestCases;
    while(TestCases--)
    {
        solve_case();
    }
    return 0;
}
