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
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

/*
    @Author: Saarang Srinivasan
    Handle: saarang123 on all platforms.
*/

const int N=200002;
vi graph[N];
int vis[N]={0};

vi bfs(int src)
{
    queue<int> q;
    vi ret;
    ret.pb(src);
    vis[src] = 1;
    q.push(src);
    while(!q.empty())
    {
        int ver = q.front(); q.pop();
        for(int adj : graph[ver])
        {
            if(!vis[adj])
            {
                q.push(adj);
                ret.pb(adj);
                vis[adj] = 1;
            }
        }
    }
    return ret;
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
    }
    vii cc;
    RE(i,n)
    {
        if(vis[i]) continue;
        cc.pb(bfs(i));
    }
    int ans=0;
    REP(i,0,cc.size()-1)
    {
        int flag=1;
        REP(j,0,cc[i].size()-1)
        {
            if(graph[cc[i][j]].size()!=2)
            {
                flag=0;
            }
        }
        if(flag) ans++;
    }
    cout << ans << "\n";
    return 0;
}
