#include<bits/stdc++.h>
#define int long long
const int N = 20;
std::vector<int> g[N];
int dp[1<<N][N], lg[1<<N],adj[N][N],n;
//dp[i][j] - no. of hamiltonion walks from first bit of mask that end on j

void solve_case()
{
    int i,j,t,k,m;
    std::cin >> n >> m;
    for(i=0; i<m; i++)
    {
        std::cin >> j >> k;
        j--,k--;
        g[j].push_back(k);
        g[k].push_back(j);
        adj[j][k] = adj[k][j] = 1;
    }

    for(i=2; i<=(1<<n); i++) lg[i] = lg[i/2] + 1;            //lg[i] - highest bit in i
    for(i=0; i<=n; i++) dp[1<<i][i] = 1;
    for(int mask=0; mask < (1<<n); mask++)
    {
        if(__builtin_popcount(mask)<=1) continue;
        for(i=0; i<n; i++)
        {
            if((mask & (1<<i)) && lg[mask]!=i)
            {
                for(int u: g[i])
                    if((mask & (1<<u))) dp[mask][i] += dp[mask ^ (1<<i)][u];
            }
        }
    }
    int ans = 0;
    for(int mask=0; mask<(1<<n); mask++)
    {
        if(__builtin_popcount(mask)<3) continue;
        for(i=0; i<n; i++)
        {
            if((mask & (1<<i)) && adj[lg[mask]][i]) ans += dp[mask][i];
        }
    }
    ans = ans/2;
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
