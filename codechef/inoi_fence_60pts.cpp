#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
typedef long long ll;
int grid[2503][2503] = {0}, vis[2503][2503] = {0};


int dfs(int i, int j)
{
    if(!grid[i][j]) return 0;
    if(vis[i][j]) return 0;
    vis[i][j] = 1;
    int pres = 4 - grid[i+1][j] - grid[i-1][j] - grid[i][j+1] - grid[i][j-1];

    return pres+dfs(i+1,j)+dfs(i-1,j)+dfs(i,j+1)+dfs(i,j-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,r,c;
    cin >> r >> c >> n;
    for(i=0; i<=2500; i++)
    {
        for(j=0; j<=2500; j++)
        {
            grid[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    for(i=0; i<n; i++)
    {
        cin >> j >> k;
        grid[j][k] = 1;
    }
    int ans = -1;
    for(i=1; i<=r; i++)
    {
        for(j=1; j<=c; j++)
        {
            if(vis[i][j]) continue;
            ans = max(ans, dfs(i,j));
        }
    }
    cout << ans << "\n";

    return 0;
}
