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

const int N = 502;
int a[N][N], dp[N][N],n,m;
vector<pair<pii,int> > ans;

int cnt(int i, int j, int c1, int c2)
{
    if(i>n || j>m || i<1 || j<1) return 0;
    if(!a[i][j]) return 0;
    return 1 + cnt(i+c1, j+c2, c1, c2);
}

void up(int i, int j, int c1, int c2, int cnt)
{
    if(cnt==0) return;
    dp[i][j]=1;
    up(i+c1, j+c2, c1, c2, cnt-1);
}

void pls_give_AC()
{
    int i,j,t,k;
    cin >> n >> m;
    RE(i,n)
    {
        RE(j,m)
        {
            char c;
            cin >> c;
            if(c=='.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    RE(i,n)
    {
        RE(j,m)
        {
            if(!a[i][j]) continue;
            int d1 = cnt(i,j+1,0,1), d2 = cnt(i,j-1,0,-1), d3 = cnt(i+1,j,1,0), d4 = cnt(i-1,j,-1,0), mx = -1;
            if(d1 && d2 && d3 && d4)
            {
                mx = min(d1, min(d2, min(d3,d4)));
                //cout << i << " " << j << " " << mx << "\n";
                ans.pb(mp(mp(i,j),mx));
                dp[i][j] = 1;
                up(i,j+1,0,1,mx); up(i,j-1,0,-1,mx); up(i+1,j,1,0,mx); up(i-1,j,-1,0,mx);
            }
        }
    }

    RE(i,n)
    {
        RE(j,m)
        {
            if(dp[i][j]!=a[i][j])
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << ans.size() << "\n";
    FOR(i,ans.size())
    {
        cout << ans[i].f.f << " " << ans[i].f.ss << " " << ans[i].ss << "\n";
    }
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
