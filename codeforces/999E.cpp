#include<bits/stdc++.h>
#define pb push_back

const int N = 5003;
std::vector<int> g[N];
int vis[N], ok[N],c=0;
std::vector<std::pair<int,int> > cnt;

void dfs(int v)
{
    if(vis[v]) return;
    vis[v] = 1;
    for(auto u: g[v])
    {
        dfs(u);
    }
}

void dfs1(int v)
{
    if(ok[v] || vis[v]) return;
    ok[v] = 1;
    c++;
    for(auto u: g[v])
    {
        dfs1(u);
    }
}

void solve_case()
{
    int n,i,j,t,k,m;
    std::cin >> n >> m >> t;
    for(i=0; i<m; i++)
    {
        std::cin >> j >> k;
        g[j].pb(k);
    }
    dfs(t);
    for(i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        memset(ok,0,sizeof ok);
        c = 0;
        dfs1(i);
        //std::cout << i << c << "\n";
        cnt.pb(std::make_pair(c,i));
    }

    std::sort(cnt.rbegin(), cnt.rend());
    int ans = 0;
    for(auto p: cnt)
    {
        if(vis[p.second]) continue;
        //std::cout << p.first << " fishy orz " << p.second << '\n';
        ++ans;
        dfs(p.second);
    }
    std::cout << ans << "\n";
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int Testcases = 1;
    //cin >> Testcases;
    while(Testcases--)
    {
        solve_case();
    }
    return 0;
}
