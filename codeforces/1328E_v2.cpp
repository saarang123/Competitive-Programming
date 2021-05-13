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
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int N = 2e5+5;
const int T = 23;
int par[N][T], t=20, depth[N];
vii graph(N);

void setup()  //Initialization
{
    for(int i=0; i<=2e5; i++)
    {
        for(int j=0; j<=20; j++)
        {
            par[i][j] = -1;
        }
    }
}

void dfs(int v, int p, int d) //Precomputation of sparse table and depth in O(n log n)
{
    depth[v] = d;
    par[v][0] = p;
    for(int i=1; i<=20; i++)
    {
        int pa = par[v][i-1];
        if(pa!=-1)
        {
            par[v][i] = par[pa][i-1];
        }
    }
    for(int u: graph[v])
    {
        //int u = graph[v][i];
        if(u==p) continue;
        dfs(u,v,d+1);
    }
}

int find_kth(int a, int diff)  //O(log n)
{
    for(int i=0; i<=20; i++)      //Can also loop from T-1 to 0 if bottom thing used.
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

    for(int i=20; i>=0; i--)
    {
        if(par[a][i]!=par[b][i])
        {
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

bool cmp(int v, int u)
{
    return depth[v]>depth[u];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,k,m;
    setup();
    cin >> n >> m;
    RE(i,n-1)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    dfs(1,-1,0);

    while(m--)
    {
        cin >> k;
        vi q;
        RE(i,k) {cin >> j; q.pb(j);};
        sort(all(q), cmp); //Sorting in increasing depth.
        //q[0] is lowest depth element
        bool pos = true;
        REP(i,0,k-1)
        {
            j = lca(q[0], q[i]);
            //LCA of lowest depth element and q[i] should either be one of them or parent of q[i]
            if(depth[j]+1<depth[q[i]])
            {
                pos = false;
                break;
            }
        }
        cout << (pos==1 ? "YES\n":"NO\n");
    }

    return 0;
}
