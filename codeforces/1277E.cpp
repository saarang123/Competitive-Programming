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


//Removing A and finding no. of nodes that cant be visited
//Same with B.
//Answer is their product. It is basically finding no. of nodes "behind" A and B.

const int N = 2e5+4;
vi graph[N];
int vis[N] = {0};

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = true;
    REP(i,0,graph[v].size()-1)
    {
        dfs(graph[v][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,a,b;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> a >> b;
        RE(i,n)
        {
            graph[i].clear();
            vis[i] = 0;
        }
        RE(i,m)
        {
            cin >> j >> k;
            graph[j].pb(k);
            graph[k].pb(j);
        }

        ll cnt1=0,cnt2=0;
        vis[b] = true;
        dfs(a);
        RE(i,n)
        {
            if(!vis[i]) cnt1++;
        }

        RE(i,n) vis[i]=0;
        vis[a]=true;
        dfs(b);
        RE(i,n)
        {
            if(!vis[i]) cnt2++;
        }

        cout << cnt1*cnt2 << "\n";
    }
    return 0;
}
