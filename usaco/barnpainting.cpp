#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

const int N = 1e5+5;
vii graph(N);
ll dp[N][4] = {-1}, col[N]={0};

void dfs(int src, int c, int par)
{
    if(dp[src][c]!=-1)
        return;
    dp[src][c] = 0;
    ll ans = 1;
    for(int j=0; j<graph[src].size(); j++)
    {
        int v = graph[src][j];
        if(v==par) continue;
        ll pres = 0;
        for(int i=1; i<4; i++)
        {

            if(c==i) continue;
            dfs(v,i,src);
            pres = (pres + dp[v][i])%MOD;
            //cout << v << " " << i << "\n";
            //cout << pres << "\n";
        }
        ans = (ans*pres)%MOD;
    }
    dp[src][c] = ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    int n,i,j,t,k,m;
    cin >> n >> m;
    for(i=1; i<n; i++)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    for(j=1; j<4; j++)
    {
        for(i=1; i<=n; i++)
        {
            dp[i][j] = -1;
            col[i] = 0;
        }
    }
    for(i=1; i<=m; i++)
    {
        cin >> j >> k;
        for(t=1; t<4; t++)
        {
            if(t==k) continue;
            dp[j][t] = 0;
        }
    }

    /*
    RE(j,3)
    {
        cout << j << ":\n";
        RE(i,n)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */

    dfs(1,1,INF);
    dfs(1,2,INF);
    dfs(1,3,INF);
    ll ans=0;

    ans = (dp[1][1]+dp[1][2]+dp[1][3])%MOD;
    cout << ans << "\n";
    return 0;
}
