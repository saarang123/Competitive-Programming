#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
int n;
ll grid[2][100005], dp[2][100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll i,j,m1=-1, m2=-1;
    cin >> n;
    for(i=1; i<=n; i++)
        cin >> grid[0][i];
    for(i=1; i<=n; i++)
        cin >> grid[1][i];
    dp[0][n] = grid[0][n];
    dp[1][n] = grid[1][n];
    m1 = dp[0][n];
    m2 = dp[1][n];
    for(i=n-1; i>=1; i--)
    {
        dp[0][i] = grid[0][i] + m2;
        dp[1][i] = grid[1][i] + m1;
        m1 = max(m1, dp[0][i]);
        m2 = max(m2, dp[1][i]);
    }
    ll ans = -1;
    for(i=0; i<2; i++)
    {
        for(j=1; j<=n; j++)
            ans = max(ans, dp[i][j]);
    }
    cout << ans << "\n";
    return 0;
}
