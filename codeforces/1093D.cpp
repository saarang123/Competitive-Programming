#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 998244353
#define mod 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

const int N = 3e5+5;
vii graph(N);
ll col[N] = {-1}, twos[N];
ll cnt[2] = {0};
bool pos = 1;

void dfs(int src, int c)
{
    col[src] = c;
    cnt[c]++;
    for(int v: graph[src])
    {
        if(col[v] == -1) dfs(v,!c);
        if(col[v]==col[src])
        {
            pos = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        twos[0] = 1;
        for(i=1; i<=n; i++)
        {
            twos[i] = (twos[i-1]*2)%MOD;
        }
        for(i=1; i<=n; i++)
        {
            graph[i].clear();
        }
        for(i=1; i<=m; i++)
        {
            cin >> j >> k;
            graph[j].pb(k);
            graph[k].pb(j);
        }
        ll ans = 1;
        for(i=1; i<=n; i++) col[i] = -1;

        for(i=1; i<=n; i++)
        {
            if(col[i]!=-1) continue;
            pos = 0;
            cnt[0] = 0;
            cnt[1] = 0;
            dfs(i,0);
            if(pos)
            {
                cout << 0 << "\n";
                break;
            }
            ll pres = (twos[cnt[0]]+twos[cnt[1]])%MOD;
            ans = (ans*pres)%MOD;
        }
        if(!pos) cout << ans << "\n";
    }
    return 0;
}
