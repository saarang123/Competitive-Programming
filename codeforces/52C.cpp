#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
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

const int N = 2e5+5;
int lazy[4*N], t[4*N], a[N];

void build(int a[], int v, int tl, int tr)  //Building both segment trees simultaneously.
{
    if(tl==tr)
    {
        t[v] = a[tl];
        lazy[v] = 0;
    }
    else
    {
        int tm = (tl+tr)/2;
        build(a, 2*v, tl, tm);
        build(a, 2*v+1, tm+1, tr);
        t[v] = min(t[2*v], t[2*v+1]);  //Max query for lazy tree.
    }
}

void push(int v)   //Used for pushing lazy values in a segment tree for lazy propagation.
{
    t[2*v] += lazy[v];
    lazy[2*v] += lazy[v];
    t[2*v+1] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int add)   //Range update in a segment tree.
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[v] += add;
        lazy[v]+=add;
    }
    else
    {
        push(v);
        int tm = (tl+tr)/2;
        update(2*v, tl, tm, l, min(r,tm), add);
        update(2*v+1, tm+1, tr, max(tm+1,l), r, add);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 1e17;
    if(l<=tl && tr<=r)
    {
        return t[v];
    }
    push(v);
    int tm = (tl+tr)/2;
    return min(query(2*v, tl, tm, l, min(tm,r)), query(2*v+1, tm+1, tr, max(l,tm+1), r));
}

void solve_case()
{
    int n,i,j,k,m;
    cin >> n;
    RE(i,n) cin >> a[i-1];
    build(a, 1, 0, n-1);
    cin >> m;
    string s7;
    getline(cin,s7);
    while(m--)
    {
        string s,s2;
        getline(cin, s);
        stringstream geek(s);
        int l=-1,r=-1,v=0;
        geek >> l >> r;
        if(geek >> v) k = 0;
        else k = 1;
        if(l>=n || r>=n || l<0 || r<0) continue;

        if(!k)
        {
            if(l<=r)
            {
                //cout << "up1\n";
                update(1, 0, n-1, l, r, v);
            }
            else
            {
                //cout << "up2\n";
                update(1,0,n-1,0,r, v);
                update(1,0,n-1,l,n-1, v);
            }
        }
        else
        {
            if(l<=r)
            {
                //cout << "q1\n";
                cout << query(1,0,n-1,l,r) << "\n";
            }
            else
            {
                //cout << "q2\n";
                cout << min(query(1,0,n-1,0,r), query(1,0,n-1,l,n-1)) << "\n";
            }
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