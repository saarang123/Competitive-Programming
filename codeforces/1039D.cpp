#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=0; i<n; i++)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

const int mod = 998244353;
vii graph(n);
int col[n] = {-1}, vis[n] = {0}};


void dfs(int src, int c2)
{
    int c = c2^1;
    if(vis[src]) return;
    vis[src] = 1;
    for(int adj : graph[src])
    {
        if(col[adj]!=-1) continue;
        col[adj] = c;
        dfs(adj, c);
    }
    return ;
}

bool check(int src, int c2)
{
    int c = c2^1;
    if(vis[src])
    {
        return col[src]==c;
    }

    vis[src] = 1;
    for(int adj : graph[src])
    {
        if(col[adj]!=c) return false;
        bool ret = check(adj, c);
        if(!ret) return false;
    }
    return true;
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
        cin >> n >> m;
        for(i=0; i<m; i++)
        {
            cin >> j >> k;
            j--,k--;
            graph[j].pb(k);
            graph[k].pb(j);
        }
        int ans = 0;
        for(i=0; i<n; i++)
            vis[i]=0;
        col[0] = 0;
        dfs(0,0);
        for(i=0; i<n; i++)
            vis[i]=0;
        bool a = check(0,0);
        if(a)
        {
            pres = 1;
            for(i=0;i<n; i++)
            {
                if(col[i]) pres*=2;
                else pres*=1;
            }
            ans+=pres;
        }

        col[0] = 1;
        for(i=0; i<n; i++)
            vis[i]=0;
        dfs(0,1);
        for(i=0; i<n; i++)
            vis[i]=0;
        bool a = check(0,1);
        if(a)
        {
            pres = 1;
            for(i=0;i<n; i++)
            {
                if(col[i]) pres*=2;
                else pres*=1;
            }
            ans+=pres;
        }
        cout << ans << "\n";
    }
    return 0;
}
