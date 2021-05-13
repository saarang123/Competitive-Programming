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

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

//-------------------------------------------------Template Ends------------------------------------------------------/

const int N = 103;
int a[N][N][N];

void read(int n, int m,int k)
{
    RE(l,n)
    {
        RE(i,m)
        {
            RE(j,k)
            {
                char c;
                cin >> c;
                if(c=='1') a[i][j][l] = 1;
                else a[i][j][l] = 0;
            }
        }
    }
}

bool check(int i, int j, int k)
{
    if(!a[i][j][k]) return false;
    if((a[i-1][j][k] && a[i+1][j][k]) ||
       (a[i][j-1][k] && a[i][j+1][k]) ||
       (a[i][j][k-1] && a[i][j][k+1])) return true;

    if(a[i-1][j][k])
    {
        if(a[i][j+1][k] && !a[i-1][j+1][k]) return true;
        if(a[i][j][k+1] && !a[i-1][j][k+1]) return true;
    }

    if(a[i][j-1][k])
    {
        if(a[i+1][j][k] && !a[i+1][j-1][k]) return true;
        if(a[i][j][k+1] && !a[i][j-1][k+1]) return true;
    }

    if(a[i][j][k-1])
    {
        if(a[i+1][j][k] && !a[i+1][j][k-1]) return true;
        if(a[i][j+1][k] && !a[i][j+1][k-1]) return true;
    }
    return false;
}

void solve_case()
{
    int n,i,j,t,k,m;
    cin >> n >> m >> k;
    read(n,m,k);
    int ans = 0;
    RE(i,n) RE(j,m) RE(l,k) ans += check(j,l,i);
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
