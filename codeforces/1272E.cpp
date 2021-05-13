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

/*
    @Author: Saarang Srinivasan
    Handle: saarang123 on all platforms.
    Soln:
    Use multi-source BFS.
    If you use the graph normally, u will not be able to find out the shortest path
    efficiently as u have to find all possible ways that vertex V can be reached from all other nodes.
    Hence, we invert the graph.
    Now, we run two multi-src BFSs. One on all odd a[i] nodes, and one on all even a[i] nodes.
    During each bfs,
    For node v and adjacent u, d[u] = d[v]+1 if d[u]=INF(even) and d[v]=0 or sm value(odd).
    Same thing with even/odd.
*/

const int N = 2e5+5;
vii graph(N);
ll a[N], d[N]={-1}, ans[N][2]={0};
queue<int> q;

void bfs()
{
    while(!q.empty())
    {
        int i = q.front();q.pop();
        for(int v: graph[i])
        {
            if(d[v]!=INF) continue;
            d[v] = d[i]+1;
            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        if(i+a[i]<=n) graph[i+a[i]].pb(i);
        if(i-a[i]>0) graph[i-a[i]].pb(i);
    }


    for(j=0; j<=1; j++)
    {
        while(!q.empty()) q.pop();
        for(i=1; i<=n; i++)
        {
            d[i] = INF;
            if(a[i]%2==j)
            {
                q.push(i);
                d[i] = 0;
            }
        }
        bfs();
        for(i=1; i<=n;i++)
            ans[i][j] = d[i];
    }

    for(i=1; i<=n; i++)
    {
        if(ans[i][!(a[i]%2)]==INF) cout << -1 << " ";
        else cout << ans[i][!(a[i]%2)] << " ";
    }
    cout << "\n";
    return 0;
}
