#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
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

struct Edge
{
    int u,v,w;
    bool operator<(Edge const& other)
    {
        return w < other.w;
    }
};

const int N = 2003;
vpii xy(N), eded;
int c[N],k[N];
int cost = 0;
vi parent, len, powd;
vector<Edge> edges;

void mk_set(int v)
{
    parent[v] = v;
    len[v] = 1;
}

int find_set(int v)
{
    if(parent[v]==v) return parent[v];
    return parent[v]=find_set(parent[v]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a!=b)
    {
        if(len[a]<len[b])
            swap(a,b);
        parent[b] = a;
        len[a]+=len[b];
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,m;
    cin >> n;
    parent.resize(n+5);len.resize(n+5);
    REP(i,0,n+1) mk_set(i);
    RE(i,n)
    {
        cin >> j >> t;
        xy[i] =(mp(j,t));
    }
    RE(i,n) cin >> c[i];
    RE(i,n) cin >> k[i];

    RE(i,n)
    {
        Edge ed{0,i,c[i]};
        edges.pb(ed);
    }
    RE(i,n)
    {
        REP(j,i+1,n)
        {
            int d = abs(xy[i].f-xy[j].f) + abs(xy[i].ss-xy[j].ss);
            Edge ed{i,j,(k[i]+k[j])*d};
            edges.pb(ed);
        }
    }

    sort(all(edges));
    int lol = edges.size();
    for(i=0; i<lol; i++)
    {
        Edge e = edges[i];
        if(find_set(e.u)!=find_set(e.v))
        {
            cost+=e.w;
            if(e.u==0) powd.pb(e.v);
            else eded.pb(mp(e.u,e.v));
            union_set(e.u,e.v);
        }
    }
    cout << cost << "\n";
    cout << powd.size() << "\n";
    print(powd);
    cout << eded.size() << "\n";
    for(auto p: eded) cout << p.f << " " << p.ss << "\n";

    return 0;
}
