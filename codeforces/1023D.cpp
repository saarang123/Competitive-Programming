#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
//#define int long long
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
#define rip signed
#define kobe main()
#define bryant ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);

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
#define FOR(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

#define ok(v) 2*v

const int N = 2e5+3;
int a[N], n, t[4*N], lazy[4*N];
vi q[N];

void push(int v)
{
    if(lazy[v])
    {
        t[ok(v)] = t[ok(v)+1] = t[v];
        lazy[ok(v)] = lazy[ok(v)+1] = 1;
        lazy[v] = 0;
    }
}

void rupdate(int tl, int tr, int v, int l, int r, int val)
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[v] = val;
        lazy[v] = 1;
        return;
    }
    push(v);
    int tm = (tl+tr) >> 1;
    rupdate(tl, tm, ok(v), l, min(r,tm), val);
    rupdate(tm+1,tr, ok(v)+1, max(tm+1,l), r, val);
    t[v] = t[ok(v)] + t[ok(v)+1];
}

void update(int l, int r, int val)
{
    rupdate(1, n, 1, l, r, val);
}

int sum(int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl==l & tr==r) return t[v];
    push(v);
    int tm = (tl+tr) >> 1;
    return sum(ok(v), tl, tm, l, min(r,tm)) + sum(ok(v)+1, tm+1, tr, max(l,tm+1), r);
}

void pls_give_AC()
{
    int i,j,k,m;
    cin >> n >> k;
    RE(i,n)
    {
        cin >> a[i];
    }
    int cnt=0, fl=0;
    RE(i,n)
    {
        fl = max(fl,a[i]);
        if(a[i]==0) cnt++;
    }
    if(fl<k && !cnt)
    {
        cout << "NO\n";
        return;
    }
    if(fl<k)
    {
        RE(i,n)
        {
            if(a[i]==0)
            {
                a[i] = k;
                break;
            }
        }
    }
    a[0] = 0, a[n+1] = 0;
    RE(i,n)
    {
        if(!a[i] && a[i-1]) a[i] = a[i-1];
    }
    FO(i,n)
    {
        if(!a[i] && a[i+1]) a[i] = a[i+1];
    }
    RE(i,n) q[a[i]].pb(i);

    for(i=1;i<=k;i++)
    {
        if(!q[i].size())
        {
            continue;
        }
        int p1 = *q[i].begin(), p2 = *q[i].rbegin();
        //cout << m1 << " " << m2 << " " << p1 << " " << p2 << "\n";
        if(sum(1,1,n,p1,p2))
        {
            cout << "NO\n";
            return;
        }
        FOR(j,q[i].size())
        {
            update(q[i][j], q[i][j], 1);
        }

    }
    cout << "YES\n";
    RE(i,n) cout << a[i] << " "; cout << "\n";
}

rip kobe
{
    bryant;
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        pls_give_AC();
    }
    return 0;
}
