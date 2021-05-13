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

#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b)/gcd(a, b)

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
//order_of_key (k) : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).

#define trav(i,a) for(auto i: a)
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 5e5+2;
int a[N], n, t[4*N];

void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl+tr)>>1;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        t[v] = gcd(t[2*v], t[2*v+1]);
    }
}

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr)
    {
        t[v] = val;
        return;
    }
    int tm = (tl+tr)>>1;
    if(pos<=tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    t[v] = gcd(t[2*v], t[2*v+1]);
}

int query(int v, int tl, int tr, int l, int r, int x)
{
    if(l>r) return n+1;
    if(l<=tl && tr<=r)
    {
        if(t[v]%x==0) return n+1;
        if(tl==tr) return tl;
        int tm = (tl+tr)>>1;
        int q1 = query(2*v, tl, tm, l, min(tm, r), x);
        if(q1!=n+1) return q1;
        return query(2*v+1, tm+1, tr, max(tm+1, l), r, x);
    }
    int tm = (tl+tr)>>1;
    int q1 = query(2*v, tl, tm, l, min(tm, r), x);
    if(q1!=n+1) return q1;
    return query(2*v+1, tm+1, tr, max(tm+1, l), r, x);
}

int query(int l, int r, int x)
{
    return query(1, 1, n, l, r, x);
}

void update(int pos, int val)
{
    update(1, 1, n, pos, val);
}

void solve_case()
{
    int i,j,k,m;
    cin >> n;
    RE(i,n) cin >> a[i];
    build(1, 1, n);
    int q;

    cin >> q;
    while(q--)
    {
        int tp;
        cin >> tp;
        if(tp==1)
        {
            int l,r,x;
            cin >> l >> r >> x;
            int tmp = query(l, r, x);
            if(tmp==n+1) cout << "YES\n";
            else
            {
                int cur = query(tmp+1, r, x);
                if(cur==n+1) cout << "YES\n";
                else cout << "NO\n";
            }
        }
        else
        {
            int pos, x;
            cin >> pos >> x;
            update(pos, x);
        }
    }

}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
