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

const int N = 1003;
pii c[N][N], dp[N][N][2];
char par[N][N][2];
string ans = "";

int lg(int n, int r)
{
    int cnt = 0;
    while(n%r==0 && n>0)
    {
        n /= r;
        cnt++;
    }
    return cnt;
}

pii add(pii a, pii b)
{
    return mp(a.f+b.f, a.ss+b.ss);
}

pii remin(pii a, pii b)
{
    if(a.ss < b.ss) return a;
    if(b.ss < a.ss) return b;
    return a.f < b.f ? a:b;
}

int cnt(pii a)
{
    return min(a.f, a.ss);
}


void soln(int i, int j, int k)
{
    if(i<1 || j<1) return;
    if(i==1 && j==1) return;
    ans += par[i][j][k];
    if(par[i][j][k] == 'R') soln(i,j-1,k);
    else soln(i-1,j,k);
}

void solve_case()
{
    int n,i,j,t,k,m=-1;
    cin >> n;
    RE(i,n)
    {
        RE(j,n)
        {
            cin >> k;
            if(k==0) m = i;
            c[i][j] = mp(lg(k,2), lg(k,5));
        }
    }
    dp[1][1][0] = dp[1][1][1] = c[1][1];
    par[1][1][0] = par[1][1][1] = 'x';
    RE(i,n)
    {
        RE(j,n)
        {
            if(i==1 && j==1) continue;
            if(i==1)
            {
                dp[i][j][0] = add(dp[i][j-1][0], c[i][j]);
                dp[i][j][1] = add(dp[i][j-1][1], c[i][j]);
                par[i][j][0] = par[i][j][1] = 'R';
            }
            else if(j==1)
            {
                dp[i][j][0] = add(dp[i-1][j][0], c[i][j]);
                dp[i][j][1] = add(dp[i-1][j][1], c[i][j]);
                par[i][j][0] = par[i][j][1] = 'D';
            }
            else
            {
                dp[i][j][0] = min(add(dp[i-1][j][0], c[i][j]), add(dp[i][j-1][0], c[i][j]));
                if(dp[i][j][0] == add(dp[i-1][j][0], c[i][j])) par[i][j][0] = 'D';
                else par[i][j][0] = 'R';

                dp[i][j][1] = remin(add(dp[i-1][j][1], c[i][j]), add(dp[i][j-1][1], c[i][j]));
                if(dp[i][j][1] == add(dp[i-1][j][1], c[i][j])) par[i][j][1] = 'D';
                else par[i][j][1] = 'R';

            }
        }
    }
    int ans1 = cnt(dp[n][n][0]), ans2 = cnt(dp[n][n][1]), tot = -1, ind = -1;
    if(ans1<=ans2)
    {
        tot = cnt(dp[n][n][0]);
        ind = 0;
    }
    else
    {
        tot = cnt(dp[n][n][1]);
        ind = 1;
    }
    if(m!=-1 && 1<=tot)
    {
        cout << 1 << "\n";
        RE(i,m-1) cout << "D";
        RE(i,n-1) cout << "R";
        REP(i,m,n-1) cout << "D";
        cout << "\n";
        return;
    }
    cout << tot << "\n";
    soln(n,n,ind);
    reverse(all(ans));
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
