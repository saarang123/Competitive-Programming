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
vii graph(N);
int pa[N], dt[N], in[N], out[N];
vi order;

void dfs(int v, int p, int d)
{
    pa[v] = max(p,1);
    dt[v] = d;
    order.pb(v);
    in[v] = order.size()-1;
    for(int u: graph[v])
    {
        if(u==p) continue;
        dfs(u,v,d+1);
    }
    out[v] = order.size()-1;
}

bool cmp(int v, int u)
{
    return dt[v]<dt[u];
}

bool check(int v, int u)
{
    return (in[v]<=in[u] && out[u]<=out[v]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
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
        vi query;
        RE(i,k) {cin >> j; query.pb(pa[j]);}
        //Distance from node can be at-most 1, therefore either the node or its parent is included in the path.
        sort(all(query),cmp); //Sorting based on depth so higher parents are first.
        bool pos = 1;
        RE(i,k-1)
        {
            if(!check(query[i-1], query[i]))   //Checking if the nodes belong to same subtree.
            {
               pos = 0;
               break;
            }
        }
        if(pos) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
