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
*/

const int V=1005;
int ds[V]={INF}, dt[V]={INF};
vii graph(V);
int ed[V][V] = {0};

void dijkstra(int src)
{
    RE(i,V) ds[i]=INF;
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push(mp(0,src));
    ds[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().ss;
        pq.pop();
        for(int v: graph[u])
        {
            if(ds[v]>ds[u]+1)
            {
                ds[v] = ds[u]+1;
                pq.push(mp(ds[v],v));
            }
        }
    }
}

void dijkstra2(int src)
{
    RE(i,V) dt[i]=INF;
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push(mp(0,src));
    dt[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().ss;
        pq.pop();
        for(int v: graph[u])
        {
            if(dt[v]>dt[u]+1)
            {
                dt[v] = dt[u]+1;
                pq.push(mp(dt[v],v));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,s;
    cin >> n >> m >> s >> t;
    RE(i,m)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
        ed[j][k]=1;
        ed[k][j]=1;
    }
    dijkstra(s);
    dijkstra2(t);
    //RE(i,n) cout << ds[i] << " "; cout <<"\n";
    //RE(i,n) cout << dt[i] << " "; cout << "\n";
    int ans=0;
    RE(i,n)
    {
        REP(j,i+1,n)
        {
            if(ed[i][j]) continue;
            if(ds[i]+dt[j]+1 >= ds[t] && ds[j]+dt[i]+1 >= ds[t])
            {
                ans++;
                //cout << i << " " << j << " " << ds[i] << " " << dt[j] << " " << ds[j] << " " << dt[i] << "\n";
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
