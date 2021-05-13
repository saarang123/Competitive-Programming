#include <stdio.h>
#include <string.h>
#define MAX 600
int min(int a, int b, int c)
{
    int ans = a;
    if(b<ans)
        ans = b;
    if(c<ans)
        ans = c;
    return ans;
}
int dp_soln(char a[], char b[], int m, int n)
{
    int dp[m+1][n+1],i,j;
    for(i=0;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==0) 
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(a[i-1]==b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}
int main()
{
    char a[MAX] = "saturday", b[MAX] = "sunday";
    prinf("%d", dp_soln(a, b, strlen(a), strlen(b)));
    return 0;
}