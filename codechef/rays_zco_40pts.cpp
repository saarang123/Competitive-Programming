#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
int n,m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,xi,yi,w,b;
    cin >> n >> m >> w >> b;
    int grid[n+1][m+1];
    int dp[n+1][m+1];
    for(i=0; i<n+1; i++)
    {
        for(j=0; j<m+1; j++)
        {
            grid[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    for(i=0; i<w;i++)
    {
        cin >> xi >> yi;
        xi--,yi--;
        grid[xi][yi] = 1;
    }
    for(i=0; i<b; i++)
    {
        cin >> xi >> yi;
        xi--,yi--;
        grid[xi][yi] = -1;
        dp[xi][yi] = 0;
    }

    int prev,curr;
    for(i=n-1; i>=0; i--)
    {
        prev=-1;curr=-1;
        for(j=m-1; j>=0; j--)
        {
            if(grid[i][j] == -1)
            {
                dp[i][j] = 1;
                prev = -1, curr = -1;
            }
            else if(grid[i][j] == 1)
            {
                if(curr==-1)
                {
                    curr = j;
                    dp[i][j] = dp[i][j+1]+1;
                }
                else if(curr!=-1)
                {
                    prev = curr;
                    curr = j;
                    dp[i][j] = prev-j+1;
                }
            }
            else
            {
                dp[i][j] = 1 + dp[i][j+1];
            }
        }
    }
    ll ans = 0;
    /*
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(grid[i][j]==0)
                ans+=dp[i][j];
        }
    }
    cout << ans << "\n";
    return 0;
}
