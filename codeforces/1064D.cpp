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

const int N = 2003;
pii dist[N][N];
int a[N][N];
void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m;
    int x,y;
    cin >> x >> y;
    int cnt1,cnt2;
    cin >> cnt1 >> cnt2;
    RE(i,n)
    {
        RE(j,m)
        {
            char c;
            cin >> c;
            if(c=='.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    RE(i,n) RE(j,m) dist[i][j] = mp(-1,-1);
    priority_queue<pair<pii,pii>, vector<pair<pii,pii>>, greater<pair<pii,pii>> > pq;
    dist[x][y] = mp(0,0);
    pq.push(mp(dist[x][y],mp(x,y)));
    while(!pq.empty())
    {
        int v = pq.top().ss.f, u = pq.top().ss.ss;
        pq.pop();

        if(a[v+1][u] && dist[v+1][u]==mp(-1,-1))
        {
            dist[v+1][u] = dist[v][u];
            pq.push(mp(dist[v+1][u], mp(v+1,u)));
        }
        if(a[v-1][u] && dist[v-1][u]==mp(-1,-1))
        {
            dist[v-1][u] = dist[v][u];
            pq.push(mp(dist[v-1][u], mp(v-1,u)));
        }
        if(a[v][u+1] && dist[v][u+1]==mp(-1,-1))
        {
            dist[v][u+1] = mp(dist[v][u].f, dist[v][u].ss+1);
            pq.push(mp(dist[v][u+1], mp(v,u+1)));
        }
        if(a[v][u-1] && dist[v][u-1]==mp(-1,-1))
        {
            dist[v][u-1] = mp(dist[v][u].f+1, dist[v][u].ss);
            pq.push(mp(dist[v][u-1], mp(v,u-1)));
        }
    }
    int ans = 0;
    RE(i,n)
    {
        RE(j,m)
        {
            if(dist[i][j]!=mp(-1,-1) && dist[i][j].f<=cnt1 && dist[i][j].ss<=cnt2) ans++;
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
