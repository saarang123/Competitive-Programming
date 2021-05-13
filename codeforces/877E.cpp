
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
#define int long long
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

#define lc(v) 2*v
#define rc(v) 2*v + 1
const int N = 2e5+5;
int t[4*N], lazy[4*N], ord[N], tin[N], a[N], tout[N], tx=0;
vi graph[N];

void dfs(int v, int p)
{
    ord[tx] = a[v];
    tin[v] = tx++;
    for(int u: graph[v])
    {
        if(u==p) continue;
        dfs(u,v);
    }
    tout[v] = tx-1;
}

void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v] = ord[tl];
        lazy[v] = 0;
    }
    else
    {
        int tm = (tl+tr)>>1;
        build(lc(v),tl, tm);
        build(rc(v), tm+1, tr);
        t[v] = t[2*v] + t[2*v+1];
    }
}

void push(int v, int l, int r)
{
    if(lazy[v])
    {
        int m = (l+r)>>1;
        t[lc(v)] = (m-l+1) - t[lc(v)];  //All 0s turn 1 and all 1s turn 0.
        t[rc(v)] = (r-m) - t[rc(v)];
        lazy[lc(v)] ^= 1;
        lazy[rc(v)] ^= 1;
        lazy[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r)
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[v] = r-l+1 - t[v];
        lazy[v] ^= 1;
    }
    else
    {
        push(v, tl, tr);
        int tm = (tl+tr)>>1;
        update(lc(v), tl, tm, l, min(r,tm));
        update(rc(v), tm+1, tr, max(l,tm+1), r);
        t[v] = t[lc(v)] + t[rc(v)];
    }
}

int sum(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl==l && tr==r)
        return t[v];
    push(v, tl, tr);
    int tm = (tl+tr)>>1;
    return sum(lc(v), tl, tm, l, min(r,tm)) + sum(rc(v), tm+1, tr, max(l,tm+1),r);
}

void solve_case()
{
    int n,i,k,q,j,m;
    cin >> n;
    RE(i,n-1)
    {
        cin >> j;
        graph[i+1].pb(j);
        graph[j].pb(i+1);
    }
    RE(i,n) cin >> a[i];
    dfs(1,-1);
    //RE(i,n) cout << ord[i-1] << " "; cout << "\n";
    //RE(i,n) cout << tin[i] << " "; cout << "\n";
    //RE(i,n) cout << tout[i] << " "; cout << "\n";
    build(1,0,n-1);
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s >> k;

        if(s=="get")
        {
            cout << sum(1, 0, n-1, tin[k], tout[k]) << "\n";
        }
        else
        {
            update(1, 0, n-1, tin[k], tout[k]);
        }

    }
}

signed main()
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
