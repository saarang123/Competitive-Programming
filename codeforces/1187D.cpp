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

const int N = 3e5+5;
int a[N], b[N], t[4*N];
set<int> p[N];

void update(int v, int tl, int tr, int pos, int val)
{
    if(tl==tr)
        t[v] = val;
    else
    {
        int tm = (tl+tr)>>1;
        if(pos<=tm)
            update(2*v, tl, tm, pos, val);
        else
            update(2*v+1, tm+1, tr, pos, val);
        t[v] = min(t[2*v], t[2*v+1]);
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l>r) return INF;
    if(l<=tl && tr<=r)
        return t[v];
    int tm = (tl+tr)>>1;
    return min(query(2*v, tl, tm, l, min(r,tm)), query(2*v+1, tm+1, tr, max(l,tm+1), r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    while(c--)
    {
        int n,i,j,k,m;
        cin >> n;
        RE(i,n) p[i].clear();
        RE(i,n)
        {
            cin >> j;
            p[j].insert(i-1);
        }
        RE(i,n) cin >> b[i-1];
        REP(i,0,4*n) t[i] = INF;

        RE(i,n)
        {
            if(!p[i].empty()) update(1,0,n-1,*p[i].begin(), i);
            /*
            for(setitr it = p[i].begin(); it!=p[i].end(); it++)
            {
                update(1,0,n-1,*it,i);
            }
            */
        }
        bool ok = true;
        REP(i,0,n-1)
        {
            if(p[b[i]].empty()) {ok = false; break; }
            j = *p[b[i]].begin();
            int q = query(1,0,n-1,0,j);
            if(q<b[i])
            {
                //cout << i << " " << j << " " << b[i] << "\n";
                ok = false;
                break;
            }
            update(1,0,n-1,j,INF);
            p[b[i]].erase(j);
            if(!p[b[i]].empty())
                update(1,0,n-1,*p[b[i]].begin(),b[i]);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
