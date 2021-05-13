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

const int N = 105;

int dist(pii a, pii b)
{
    return (abs(a.f-b.f) + abs(a.ss-b.ss));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a[n+1][n+1], dp[n+1][n+1];
        vpii ks[k+1];
        RE(i,n)
        {
            RE(j,n)
            {
                cin >> a[i][j];
                ks[a[i][j]].pb(mp(i,j));
            }
        }
        for(pii p: ks[k])
        {
            dp[p.f][p.ss] = 0;
        }

        /*
        RE(i,k)
        {
            for(int j = 0; j<ks[i].size(); j++)
            {
                pii p = ks[i][j];
                cout << "(" << p.f << " " << p.ss << ") ";
            }
            cout << "\n";
        }
        */

        REB(i,k-1,1)
        {
            for(pii p: ks[i])
            {
                dp[p.f][p.ss] = INF;
                for(pii p1: ks[i+1])
                {
                    dp[p.f][p.ss] = min(dp[p.f][p.ss], dp[p1.f][p1.ss]+dist(p,p1));
                }
            }
        }

        int ans = INF;
        for(pii p: ks[1])
        {
            ans = min(ans, dp[p.f][p.ss]);
        }
        cout << ans << "\n";
    }

    return 0;
}
