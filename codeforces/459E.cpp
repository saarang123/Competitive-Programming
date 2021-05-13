#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define int long long
typedef long long ll;

const int N = 3e5+2, W = 1e5+2;
vector<pair<int, int> > wts[W];
int dp[N][3];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,n,m,k;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        int l;
        cin >> j >> k >> l;
        wts[l].pb(mp(j,k));
    }
    //0 - ans end at i
    //1 is current
    int ans = 0;
    for(i=0; i<=n; i++) dp[i][0] = dp[i][1] = 0;
    for(i=1; i<=1e5; i++)
    {
        //cout << i << "hi\n";
        for(j=0; j<wts[i].size(); j++)
        {
            int u = wts[i][j].ss;
            //resets 1s
            dp[u][1] = 0;
        }
        for(j=0; j<wts[i].size(); j++)
        {
            int u = wts[i][j].ss, v = wts[i][j].f;
            //do we extend? so ans + 1
            dp[u][1] = max(dp[u][1], dp[v][0] + 1);
        }
        for(j=0; j<wts[i].size(); j++)
        {
            int u = wts[i][j].ss;
            //max 2nds also for future
            dp[u][0] = max(dp[u][0], dp[u][1]);
            ans = max(ans, dp[u][0]);
        }
    }
    cout << ans << "\n";
    return 0;
}
