
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

const int N=2e5+3;
vii graph(N);
int p[N];

pii dfs(int v, int par, int d)
{
    p[v] = par;
    pii ret = mp(d,v);
    for(int u: graph[v])
    {
        if(u==par) continue;
        ret = max(ret, dfs(u, v, d+1));
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    for(i=1; i<n; i++)
    {
        cin >> j >> k;
        graph[j].pb(k);
        graph[k].pb(j);
    }
    pii d1 = dfs(1,-1,0);
    pii d2 = dfs(d1.ss,-1,0);
    vi diam;
    int v = d2.ss;
    while(v!=d1.ss)
    {
        diam.pb(v);
        v = p[v];
    }
    if(diam.size()==n)
    {
        cout << n-1 << "\n";
        cout << diam[0] << " " << diam[1] << " " << diam.back() << "\n";
        return 0;
    }
    queue<int> q;
    vi d(n+1,-1);
    for(int i: diam)
    {
        d[i] = 0;
        q.push(i);
    }
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        for(int u: graph[v])
        {
            if(d[u]!=-1) continue;
            d[u] = d[v]+1;
            q.push(u);
        }
    }
    pii ans = mp(d[0],0);
    for(i=1; i<=n; i++)
    {
        ans = max(ans, mp(d[i],i));
    }
    cout << diam.size()+ans.f << "\n";
    cout << d1.ss << " " << d2.ss << " " << ans.ss << "\n";
    return 0;
}

