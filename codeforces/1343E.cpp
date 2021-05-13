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

#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e15;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 2e5+5;
vi g[N];
int d[N][3], p[N];

void bfs(int s, int c)
{
    queue<int> q;
    q.push(s);
    d[s][c] = 0;
    while(!q.empty())
    {
        int v = q.front(); q.pop();
        for(int i=0; i<g[v].size(); i++)
        {
            int u = g[v][i];
            if(d[u][c]!=-1) continue;
            d[u][c] = d[v][c]+1;
            q.push(u);
        }
    }
}

void solve_case()
{
    int n,i,j,t,k,m,a,b,c;
    cin >> n >> m >> a >> b >> c;
    RE(i,n) g[i].clear();
    RE(i,m) cin >> p[i];
    sort(p+1, p+m+1);
    RE(i,m)
    {
        cin >> j >> k;
        g[j].pb(k);
        g[k].pb(j);
    }
    RE(i,m) p[i] += p[i-1];
    RE(i,n)
    {
        RE(j,3) d[i][j-1] = -1;
    }
    bfs(a,0); bfs(b,1); bfs(c,2);
    int ans = 1e16;
    RE(i,n)
    {
        int dist = d[i][0] + d[i][1] + d[i][2];
        if(dist>m) continue;
        int pres = p[dist] + p[d[i][1]];
        //Choosing i as intermediate node.
        ans = min(ans,pres);
    }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
