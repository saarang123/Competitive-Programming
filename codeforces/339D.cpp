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
#define lc(v) 2*v
#define rc(v) 2*v+1

const int N = pow(2,17)+5;
ll t[4*N], a[N];

void build(int v, int tl, int tr, bool par)
{
    if(tl==tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl+tr)>>1;
        build(lc(v), tl, tm, !par);
        build(rc(v), tm+1, tr, !par);
        if(par) t[v] = t[lc(v)] | t[rc(v)];
        else t[v] = t[lc(v)] ^ t[rc(v)];
    }
}

void update(int v, int tl, int tr, int pos, int val, bool par)
{
    if(tl==tr)
    {
        t[v] = val;
        return;
    }
    int tm = (tl+tr)>>1;
    if(pos>tm) update(rc(v), tm+1, tr, pos, val, !par);
    else update(lc(v), tl, tm, pos, val, !par);
    if(par) t[v] = t[lc(v)] | t[rc(v)];
    else t[v] = t[lc(v)] ^ t[rc(v)];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,k,m;
    cin >> n >> m;
    k = pow(2,n);
    RE(i,k) cin >> a[i-1];
    build(1,0,k-1,n%2);
    while(m--)
    {
        cin >> i >> j;
        update(1,0,k-1,i-1,j, n%2);
        cout << t[1] << "\n";
    }
    return 0;
}
