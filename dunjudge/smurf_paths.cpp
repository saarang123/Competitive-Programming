#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Defines and Template
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

// ------------------------------End of Template ---------------------------------------------//


const int N = 5e5+3;
pair<long long, long long> t[4*N];  //Lazy tree
long long lazy[4*N], x, a[N], tin[N], g[4*N], tout[N], tx=0, ord[N];
//Lazy is for lazy propagation, tin, tout are entry and exit indices for each node.
//tx is pointer for tree to array and ord is array in dfs traversal order for building segtree.
vii graph(N); //adjacency list for graph

void dfs(int v, int p) //Tree to array and storing entry and exit indices.
{
    ord[tx] = a[v];
    tin[v] = tx++;
    for(int i=0; i<graph[v].size(); i++)
    {
        int u = graph[v][i];
        if(u==p) continue;
        dfs(u,v);
    }
    tout[v] = tx-1;
}

void build(long long a[], int v, int tl, int tr)  //Building both segment trees simultaneously.
{
    if(tl==tr)
    {
        t[v] = make_pair(a[tl], tl);  //Making pair of the (value, index)
        g[v] = 0;
        lazy[v] = 0;
    }
    else
    {
        int tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = max(t[2*v], t[2*v+1]);  //Max query for lazy tree.
        g[v] = g[2*v] + g[2*v+1];      //Sum query for 2nd segtree
    }
}

void pubdate(int v, int tl, int tr, int pos, int val)   //Point update in 2nd segtree
{
    if(tl==tr)
    {
        g[v] = val;
    }
    else
    {
        int tm = (tl+tr)/2;
        if(pos<=tm)
            pubdate(2*v, tl, tm, pos, val);
        else
            pubdate(2*v+1, tm+1, tr, pos, val);
        g[v] = g[2*v] + g[2*v+1];
    }
}

int sum(int v, int tl, int tr, int l, int r)  //Sum query in 2nd segtree
{
    if(l>r) return 0;
    if(tl==l && tr==r)
    {
        return g[v];
    }
    int tm = (tl+tr)/2;
    return sum(2*v, tl, tm, l, min(r,tm)) + sum(2*v+1, tm+1, tr, max(l,tm+1), r);
}

void push(int v)   //Used for pushing lazy values in a segment tree for lazy propagation.
{
    t[2*v].first += lazy[v];
    lazy[2*v] += lazy[v];
    t[2*v+1].first += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}

void rupdate(int v, int tl, int tr, int l, int r, long long add)   //Range update in a segment tree.
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[v].first += add;
        lazy[v]+=add;
    }
    else
    {
        push(v);
        int tm = (tl+tr)/2;
        rupdate(2*v, tl, tm, l, min(r,tm), add);
        rupdate(2*v+1, tm+1, tr, max(tm+1,l), r, add);
        t[v] = max(t[2*v], t[2*v+1]);
    }
}

pair<long long,long long> query(int v, int tl, int tr, int l, int r)  //Max query in the lazy tree/
{
    if(l>r) return mp(-1e17,-1);
    if(l<=tl && tr<=r)
    {
        return t[v];
    }
    push(v);
    int tm = (tl+tr)/2;
    return max(query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(l,tm+1), r));
}

signed main()
{
    //Fast I/O
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,i,j,q;
    long long k;
    cin >> n >> x;
    for(i=0; i<n; i++) cin >> a[i];
    for(i=1; i<n; i++)
    {
        cin >> j >> k;
        j--,k--;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }

    dfs(0,-1); //Tree to array with 0th node as root
    build(ord, 1, 0, n-1);  //Build

    cin >> q;  //Queries
    while(q--)
    {
        int type;
        cin >> type;
        if(type==1)
        {
            cin >> j >> k;
            j--;
            rupdate(1, 0, n-1, tin[j], tout[j], k);   //Range updating in range (entry, exit)
        }
        else
        {
            cin >> j;
            j--;
            pair<long long, long long> ind = query(1,0,n-1,0, n-1); //checking for max in whole range (0,n-1)
            while(ind.first>=x)
            {
                //cout << ind.ss << "\n";
                pubdate(1, 0, n-1, ind.second, 1);  //Point update in 2nd segtree
                rupdate(1,0,n-1,ind.second, ind.second, -1e17);  //Using range (x,x) for a point update in the lazy tree to INT_MIN
                ind = query(1,0,n-1,0, n-1);  //checking for max in whole range (0,n-1)
            }
            long long ans1 = sum(1, 0, n-1, tin[j], tout[j]);  //Sum in subtree of j
            long long ans2 = sum(1, 0, n-1, 0, n-1) - ans1;    //Sum excluding subtree of j is sum of whole tree by sum in subtree of j
            cout << ans1*ans2 << "\n";
        }
    }


    return 0;
}

