#include <bits/stdc++.h>
using namespace std;
int grid[505][505], ber[10005][3], dp[505][505];
int n, m, s1, s2;

int man_dist(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i, j, k;
    memset(dp, 0, sizeof dp);
	cin >> n >> m;
	for(i=1; i<=n; i++)
	    for(j=1; j<=n; j++)
	        cin >> grid[i][j];
	for(i=1; i<=m ; i++)
	    cin >> ber[i][0] >> ber[i][1] >> ber[i][2];
	    
	for(i=1; i<=n; i++)
	{
	    for(j=1; j<=n; j++)
	    {
	        for(k=1; k<=m; k++)
	        {
	            if(man_dist(i, j, ber[k][0], ber[k][1]) <= ber[k][2])
	            {
	                //cout << i <<" "<< j << "\n";
	                dp[i][j] = 1;
	            }
	        }
	    }
	}
	for(i=n; i>=1; i--)
	{
	    for(j=n; j>=1; j--)
	    {
	        if(dp[i][j]!=0)
	        {
	            if(i==n && j==n)
	                dp[i][j] = grid[i][j];
	            if(i==n)
	                dp[i][j] = dp[i][j+1] + grid[i][j];
	            else if(j==n)
	                dp[i][j] = dp[i+1][j] + grid[i][j];
	            else
	                dp[i][j] = max(dp[i][j+1], dp[i+1][j])+grid[i][j];
	        }
	        
	    }
	}
	
	/*
	for(i=1; i<=n; i++)
	{
	    for(j=1; j<=n; j++)
	        cout << grid[i][j] << " ";
	   cout << "\n";
	}
	cout << "\n";
	for(i=1; i<=n; i++)
	{
	    for(j=1; j<=n; j++)
	        cout << safe[i][j] << " ";
	   cout << "\n";
	}
	cout << "\n";
	for(i=1; i<=n; i++)
	{
	    for(j=1; j<=n; j++)
	        cout << dp[i][j] << " ";
	   cout << "\n";
	}
	*/
	
	if(dp[1][1]==0)
	    cout << "NO" << "\n";
	else
	    cout << "YES" << "\n" << dp[1][1];
	return 0;
}