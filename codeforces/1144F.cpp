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

const int N = 2e5+3;
vii graph(N);
int ans[N] = {-1};
vector<pii> edge;

void dfs(int src, int par)
{
    ans[src] = par;
    for(auto adj: graph[src])
    {
        if(ans[adj]!=-1) continue;
        dfs(adj, par^1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,m)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
        edge.pb(mp(j,k));
    }
    RE(i,n) ans[i] = -1;
    dfs(1,0);
    string ret;
    REP(i,0,m-1)
    {
        pii p = edge[i];
        if(ans[p.f]==ans[p.ss])
        {
            cout << "NO\n";
            return 0;
        }
        else if(ans[p.f]==0) ret+="0";
        else ret+="1";
    }
    cout << "YES\n" << ret << "\n";
    return 0;
}
