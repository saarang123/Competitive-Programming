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
const int INF = 1e18;
const int LGN = 30;

//-------------------------------------------------Template Ends------------------------------------------------------/

int dp[52][52][103],n,m,k;  //exercise
pii up[52][52][103]; //subject, ind
int a[53], b[54], c[54], in[54];
//dp[i][j][k] - Answer from 1 to i ending with subject j on day i doing total of a[j]+k exercises.

void soln(int i, int j, int k)
{
    if(i==0)
    {
        return;
    }
    soln(i-1,up[i][j][k].f, up[i][j][k].ss);
    cout << in[j] << " " << a[j]+k << "\n";
}

void solve_case()
{
    int i,j,t,k1;
    cin >> n >> m >> k1;
    vector<pair<pair<int,int>, pair<int, int> > > arr;
    RE(tt, m)
    {
        cin >> i >> j >> t;
        arr.pb(mp(mp(t,tt),mp(i,j)));
    }
    sort(all(arr));
    REP(i,0,m-1)
    {
        a[i+1] = arr[i].ss.f;
        b[i+1] = arr[i].ss.ss;
        c[i+1] = arr[i].f.f;
        in[i+1] = arr[i].f.ss; //Order has to be retained for output :(
    }
    REP(i,0,n) REP(j,0,m) REP(k,0,100) { dp[i][j][k] = -INF; up[i][j][k] = mp(-1,-1);}
    for(i=1; i<=m; i++)
    {
        for(j=0; j+a[i]<=b[i]; j++)
        {
            dp[1][i][j] = j+a[i];
            up[1][i][j] = mp(i,j);
        }
    }
    for(i=2; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            for(k=0; k+a[j]<=b[j]; k++)
            {

                for(int l=1; l<j; l++)
                {
                    int pos1 = k+a[j] - k1;     //type 1: prev+k
                    int pos2 = k+a[j];         //type 2: prev*k
                    if(c[l]==c[j]) continue;  //complexity strictly increasing.
                    //dont be a stupid fool and know the diff b/w i and j.
                    if(pos1>=a[l] && pos1<=b[l])
                    {
                        if((dp[i-1][l][pos1-a[l]]+a[j]+k) > dp[i][j][k])
                        {
                            dp[i][j][k] = dp[i-1][l][pos1-a[l]] + a[j]+k;
                            up[i][j][k] = mp(l,pos1-a[l]);
                        }
                    }
                    if(pos2%k1==0)
                    {
                        pos2 = (pos2/k1);
                        if(pos2>=a[l] && pos2<=b[l])
                        {
                            if((dp[i-1][l][pos2-a[l]]+a[j]+k) > dp[i][j][k])
                            {
                                dp[i][j][k] = dp[i-1][l][pos2-a[l]] + a[j]+k;
                                up[i][j][k] = mp(l,pos2-a[l]);
                            }
                        }
                    }
                }
            }
        }
    }

    /*
    for(i=1; i<=n; i++)
    {
        cout << i << ": \n";
        for(j=1; j<=m; j++)
        {
            cout << j << ": ";
            for(k=0; k+a[j]<=b[j]; k++)
            {
                cout << dp[i][j][k] << " ";
            }
            cout << "\n";
        }
    }
    */

    int ans = -INF;
    pii ind = mp(-1,-1);
    for(i=1; i<=m; i++)
    {
        for(j=0; j<=100; j++)
        {
            if(dp[n][i][j] > ans)
            {
                ans = dp[n][i][j];
                ind = mp(i,j);
            }
        }
    }
    if(ans<0) { cout << "NO\n"; return; }
    cout << "YES\n";
    soln(n, ind.f, ind.ss);
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
