#include <bits/stdc++.h>
using namespace std;
#define second ss
#define first f
#define mp make_pair
#define pb push_back
#define INF 1e9
#define mod (1e9+7)
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vii;

const ll N = 1e5+5;
vector<vector<ll> > graph(N);
bool vis[N] = {0};
vector<vector<ll> > cc;
ll n;

void dfs(ll i, ll j)
{
    if(vis[i]) return;
    vis[i] = 1;
    cc[j].pb(i);
    for(auto v: graph[i])
    {
        dfs(v,j);
    }
}

void comp()
{
    ll i,j = 0;
    for(i=1; i<=n; i++) vis[i] = false;
    for(i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        cc.pb({});
        dfs(i,j);
        j++;
    }
}

ll lvl(ll i, ll j)
{
    if(vis[i]) return 0;
    vis[i] = 1;
    ll ans = j;
    for(auto v: graph[i])
    {
        ans += lvl(v,j+1);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll i,j,t,m,k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cc.clear();
        for(i=1; i<=n;i++) {graph[i].clear(); vis[i]=0;}
        for(i=1; i<=m; i++)
        {
            cin >> j >> k;
            graph[j].pb(k);
            graph[k].pb(j);
        }
        comp();
        ll maxies[cc.size()][2];
        for(i=0; i<cc.size(); i++)
        {
            if(cc[i].size()%2==0){ j=0; maxies[i][0] = INF;}
            else {j=1; maxies[i][0] = -INF; }
            for(auto v: cc[i])
            {
                if(j)
                {
                    maxies[i][0] = max(v,maxies[i][0]);
                    maxies[i][1] = j;
                }
                else
                {
                    maxies[i][0] =  min(v,maxies[i][0]);
                    maxies[i][1] = j;
                }
            }
        }
        ll even=0, odd=0;
        for(i=1; i<=n; i++) vis[i] = 0;
        for(i=0; i<cc.size(); i++)
        {
            ll pres = lvl(maxies[i][0], 1);
            if(maxies[i][1]) odd+=pres;
            else even+=pres;
        }
        cout << even << " " << odd << "\n";
    }
    return 0;
}
