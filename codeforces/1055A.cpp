#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int> > graph(1005);
int vis[1005] = {0};

void dfs(int src)
{
    if(vis[src]) return;
    vis[src] = 1;
    for(int adj: graph[src])
    {
        dfs(adj);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,s,j,t,k,m;
    cin >> n >> s;
    int a[n+1];
    RE(i,n)
    {
        cin >> a[i];
    }
    RE(i,n)
    {
        REP(j,i+1,n)
        {
            if(a[i]==1 && a[j]==1)
            {
                graph[i].pb(j);
            }
        }
    }
    RE(i,n)
    {
        cin >> a[i];
    }
    RE(i,n)
    {
        REP(j,i+1,n)
        {
            if(a[i]==1 && a[j]==1)
            {
                graph[j].pb(i);
            }
        }
    }
    dfs(1);
    if(vis[s])
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
