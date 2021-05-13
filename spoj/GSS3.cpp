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

const int N = 50000+5;
int t[4*N], a[N];

void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl+tr)>>1;
        build(lc(v), tl, tm);
        build(rc(v), tm+1, tr);
        t[v] = max(max(t[lc(v)], t[rc(v)]), t[lc(v)]+t[rc(v)]);
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr)
    {
        t[v] = val;
    }
    else
    {
        int tm = (tl+tr)>>1;
        if(pos>tm)
        {
            update(rc(v), tm+1, tr, pos, val);
        }
        else
        {
            update(lc(v), tl, tm, pos, val);
        }
        t[v] = max(max(t[lc(v)], t[rc(v)]), t[lc(v)]+t[rc(v)]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl==tr)
    {
        return t[v];
    }
    int tm = (tl+tr)>>1;
    int q1 = query(lc(v), tl, tm, l, min(r,tm);
    int q2 = query(rc(v), tm+1, tr, max(l,tm+1), r);
    return max(max(q1,q2), q1+q2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n) cin >> a[i];
    build(1,1,n);
    cin >> t;
    while(t--)
    {
        cin >> i;
        if(i)
        {
            cin >> j >> k;
            cout << query(1,1,n,j,k);
        }
        else
        {
            cin >> j >> k;
            update(1,1,n,j,k);
        }
    }
    return 0;
}
