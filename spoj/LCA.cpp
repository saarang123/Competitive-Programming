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
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator

const int N = 1e3+5;
const int T = 13; //log2(N)
vii graph(N);
int par[N][T]={-1}; //Sparse table. par[n][i] gives the 2^ith parent of node n.
int depth[N];


void setup()  //Initialization
{
    for(int i=0; i<=N-5; i++)
    {
        for(int j=0; j<=T-3; j++)
        {
            par[i][j] = -1;
        }
    }
}

void dfs(int v, int p, int d) //Precomputation of sparse table and depth in O(n log n)
{
    depth[v] = d;
    par[v][0] = p;
    for(int i=1; i<=11; i++)
    {
        int pa = par[v][i-1];
        if(pa!=-1)
        {
            par[v][i] = par[pa][i-1];
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
    for(int i=0; i<=10; i++)      //Can also loop from T-1 to 0 if bottom thing used.
    {
        if((1<<i) & diff)        //or use if((1<<i) <= diff) k = k-2^i;
        {
            a = par[a][i];
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

    for(int i=10; i>=0; i--)
    {
        if(par[a][i]!=par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,q;
    cin >> q;
    for(k=1; k<=q; k++)
    {
        cin >> n;
        setup();
        for(i=1;i<=n; i++) graph[i].clear();
        for(i=1; i<=n; i++)
        {
            cin >> m;
            while(m--)
            {
                cin >> j;
                graph[j].pb(i);
                graph[i].pb(j);
            }
        }
        dfs(1,-1,0);
        cin >> t;
        cout << "Case " << k << ":\n";
        while(t--)
        {
            int a, b;
            cin >> a >> b;
            cout << lca(a,b) << "\n";
        }
    }
    return 0;
}
