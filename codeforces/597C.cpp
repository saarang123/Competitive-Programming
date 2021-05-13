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

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 1e5+2;
int t[12][4*N], a[N], n;

void update(int i, int v, int tl, int tr, int pos, int val)
{
    if(tl==tr)
    {
        t[i][v] = val;
    }
    else
    {
        int tm = (tl+tr) >> 1;
        if(pos>tm) update(i,2*v+1, tm+1, tr, pos, val);
        else update(i,2*v, tl, tm, pos, val);
        t[i][v] = t[i][2*v] + t[i][2*v+1];
    }
}

void update(int i, int pos, int val)
{
    update(i,1,1,n,pos,val);
}

int query(int i,int v, int tl, int tr, int l, int r)
{
    if(l>r) return 0;
    if(tl==l && tr==r) return t[i][v];
    int tm = (tl+tr) >> 1;
    return query(i, 2*v, tl, tm, l, min(tm,r)) +
                       query(i, 2*v+1, tm+1, tr, max(l,tm+1), r);
}

int query(int i, int l, int r)
{
    return query(i,1,1,n,l,r);
}

void solve_case()
{
    int i,j,t,k,m;
    cin >> n >> k;
    k++;
    RE(i,n) cin >> a[i];
    if(k==1)
    {
        cout << n << "\n";
        return;
    }
    update(1,a[1],1);
    int ans = 0;
    for(i=2; i<=n; i++)
    {
        for(j=k; j>=1; j--)
        {
            //if(j>i) continue;
            if(j==1)
            {
                update(j, a[i], 1);
                continue;
            }
            int pres = query(j-1, 1, a[i]-1);
            //cout << i << " " << j << " " << a[i] << " " << pres << "\n";
            update(j, a[i], pres);
            if(j==k) ans += pres;
        }
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
