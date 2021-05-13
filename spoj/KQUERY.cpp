#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Trivial merge sort tree solution

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
#define setitr multiset <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
#define lc(v) 2*v
#define rc(v) 2*v+1
const int N = 3e4+5;
vi t[4*N];
int a[N];


void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v].pb(a[tl]);
    }
    else
    {
        int tm = (tl+tr)>>1;
        build(lc(v), tl, tm);
        build(rc(v), tm+1, tr);
        merge(t[lc(v)].begin(), t[lc(v)].end(), t[rc(v)].begin(), t[rc(v)].end(), back_inserter(t[v]));
        //Above lines ensures arrays are merged in sorted order.
    }
}

int query(int v, int tl, int tr, int l, int r, int k)
{
    if(l>r) return 0;
    if(tl==l && tr==r)
    {
        return t[v].end() - upper_bound(t[v].begin(), t[v].end(), k);
    }
    int tm = (tl+tr)>>1;
    return query(lc(v), tl, tm, l, min(r,tm), k) + query(rc(v), tm+1, tr, max(l,tm+1), r, k);
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
    int ans = 0;
    cin >> t;
    while(t--)
    {
        cin >> i >> j >> k;
        /*
        //Uncomment for solution of KQUERYO
        i = i^ans;
        j = j^ans;
        k = k^ans;
        if(i<1) i=1;
        if(j>n) j=n;
        if(i>j){ans = 0; cout << ans << "\n"; continue; }
        */
        ans = query(1,1,n,i,j,k);
        cout << ans << "\n";
    }
    return 0;
}
