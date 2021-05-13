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
#define rc(v) 2*v + 1

const int N = 1e5+5;
int t[4*N][28];
string s;

void build(int v, int tl, int tr)
{
    if(tl==tr)
    {
        REP(i,0,25) t[v][i] = 0;
        t[v][s[tl]-'a'] = 1;
    }
    else
    {
        int tm = (tl+tr)/2;
        build(lc(v), tl, tm);
        build(rc(v), tm+1, tr);
        REP(i,0,25)
        {
            t[v][i] = t[lc(v)][i] + t[rc(v)][i];
        }
    }
}

void update(int v, int tl, int tr, int pos, int newval, int i)
{
    if(tl>pos || tr<pos) return;
    if(tl==tr)
    {
        t[v][i] += newval;
    }
    else
    {
        int tm = (tl+tr)/2;
        if(pos<=tm)
        {
            update(lc(v), tl, tm, pos, newval, i);
        }
        else
        {
            update(rc(v), tm+1, tr, pos, newval, i);
        }
        t[v][i] = t[lc(v)][i] + t[rc(v)][i];
    }
}

bool query(int v, int tl, int tr, int l, int r, int c)
{
    if(l>r) return 0;
    if(l>tr || r<tl) return 0;
    if(tl==l && tr==r)
        return t[v][c];
    int tm = (tl+tr)/2;
    return (query(lc(v), tl, tm, l, min(r,tm), c) || query(rc(v), tm+1, tr, max(tm+1,l), r, c));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> s >> t;
    n = s.size();
    build(1,0,n-1);
    while(t--)
    {
        cin >> i;
        if(i==1)
        {
            char c;
            cin >> j >> c;
            update(1,0,n-1,j-1,1,c-'a');
            update(1,0,n-1,j-1,-1,s[j-1]-'a');
            s[j-1] = c;
        }
        else
        {
            cin >> j >> k;
            int ans = 0;
            REP(m,0,25)
                ans += query(1,0,n-1,j-1,k-1,m);
            cout << ans << "\n";
        }
    }
    return 0;
}
