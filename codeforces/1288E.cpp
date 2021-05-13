#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// ----------------------------------------Defines and Template-------------------------------------//
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

//-------------------------------------------------Template Ends------------------------------------------------------/

#define lc(v) 2*v
#define rc(V) 2*v+1
const int N = 3e5+5;
int t[4*N],lazy[4*N],ans1[N],ans2[N], in[N];

void build(int a[], int v, int tl, int tr)
{
    if(tl==tr)
    {
        t[v] = a[tl];
        ans1[tl] = min(ans1[tl], a[tl]);
        ans2[tl] = max(ans2[tl], a[tl]);
    }
    else
    {
        int tm = (tl+tr)>>1;
        build(a,lc(v), tl, tm);
        build(a, rc(v), tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int add)
{
    if(l>r) return;
    if(tl==l && tr==r)
    {
        t[v] += add;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,k,m;
    cin >> n >> m;
    RE(i,n) a[i-1] = i;
    RE(i,n) ans1[i-1] = INF, ans2[i-1] = -1;
    while(m--)
    {
        cin >> j;
        j--;
    }
    return 0;
}
