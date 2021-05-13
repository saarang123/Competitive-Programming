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
#define FO(i,n) for(int i=0; i<n; i++)
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FOR(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2e5+3;
vi g[N];
int dt[N], cnt[N], pt[N];

void bfs(int src, int n)
{
    RE(i,n) dt[i] = -1;
    queue<int> q;
    q.push(src);
    dt[src] = 0;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int i=0; i<g[v].size(); i++)
        {
            int u = g[v][i];
            if(dt[u]!=-1)
            {
                if(dt[u] == dt[v]+1) cnt[u]++;
                continue;
            }
            dt[u] = dt[v] + 1;
            q.push(u);
        }
    }
    RE(i,n)
    {
        if(dt[i]!=-1) cnt[i]++;
    }
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,m)
    {
        cin >> j >> k;
        g[k].pb(j);
    }
    cin >> k;
    RE(i,k) cin >> pt[i];
    bfs(pt[k],n);
    //RE(i,n) cout << dt[i] << " "; cout << "\n";
    //RE(i,n) cout << cnt[i] << " "; cout << "\n";
    int m1=0,m2=0;
    RE(i,k-1)
    {
        if(dt[pt[i]] < dt[pt[i+1]]+1)
        {
            m1++;
        }
    }
    RE(i,k-1)
    {
        if(dt[pt[i]] < dt[pt[i+1]]+1)
        {
            m2++;
        }
        else
        {
            if(cnt[pt[i]]>1) m2++;
        }
    }
    cout << m1 << " " << m2 << "\n";
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
