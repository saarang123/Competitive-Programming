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
#define RE(i,n) for(int i=0; i<n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)

const int mod = 1e9+7;
const int INF = 1e8;
const int LGN = 20;

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 1e6+3;
int nxt[N][LGN],n,m;
vii vis;
string d[N], a[N];


void get(int x, int y, int &nx, int &ny)
{
	if (d[x][y] == 'U') nx = x - 1, ny = y;
	if (d[x][y] == 'R') nx = x, ny = y + 1;
	if (d[x][y] == 'D') nx = x + 1, ny = y;
	if (d[x][y] == 'L') nx = x, ny = y - 1;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    int nx=-1,ny=-1;
    get(x,y,nx,ny);
    //cout << nx << " " << ny << "\n";
    int v = x * m + y, to = nx * m + ny;
    if(!vis[nx][ny]) dfs(nx,ny);
    nxt[v][0] = to;
}


void solve_case()
{
    int i,j,t,k;
    cin >> n >> m;
    vis = vii(n+2,vi(m+2));

    int b[n+2][m+2], w[n+2][m+2];
    RE(i,n) { cin >> a[i];}
    RE(i,n) { cin >> d[i];}
    RE(i,n) RE(j,m) { vis[i][j] = 0; b[i][j] = 0; w[i][j] = 0; }
    RE(i,n) RE(j,t+1) nxt[i][j] = -1;
    RE(i,n)
    {
        RE(j,m) if(!vis[i][j]) {dfs(i,j); }    //finding nxt[v][0] for sparse table
    }
    //RE(i,n*m) cout << nxt[i][0] << " "; cout << "\n";
    t = 1;
    while((1ll<<t) <= n*m) t++;
    t--;
    for(k=1; k<=t; k++)
    {
        RE(i,n)
        {
            RE(j,m)
            {
                int v = i*m + j;
                int pa = nxt[v][k-1];
                nxt[v][k] = nxt[pa][k-1];
                //cout << v << " " << k << " " << nxt[v][k] << " " << pa << "\n";
            }
        }
    }
    int nm = n*m;
    RE(i,n)
    {
        RE(j,m)
        {
            int v = i*m + j;
            int to = v;
            for(k=t; k>=0; k--)
            {
                if((nm >> k) & 1) to = nxt[to][k];   //binary lifting to find move after n*m moves
            }
            if(a[i][j]=='0') b[to/m][to%m]++;
            else w[to/m][to%m]++;
        }
    }
    int cnt1=0, cnt2=0;
    RE(i,n)
    {
        RE(j,m)
        {
            if(b[i][j]) { cnt1++; cnt2++; }      //blacc
            else if(w[i][j]) cnt1++;            //white
        }
    }
    cout << cnt1 << " " << cnt2 << '\n';
    //RE(i,n) {RE(j,m) cout << b[i][j] << " "; cout << "\n"; }
    //RE(i,n) {RE(j,m) cout << w[i][j] << " "; cout << "\n"; }
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
