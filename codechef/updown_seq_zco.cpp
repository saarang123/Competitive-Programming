#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
int dp[3][1000005],n, a[1000005];

int f(int state, int i)
{
    if(i>n)
        return 0;
    if(dp[state][i]!=-1)
        return dp[state][i];
    else
    {
        if(i==n)
        {
            dp[state][i] = 1;
        }
        else if(state==1 && a[i]>a[i+1])
            dp[state][i] = 1;
        else if(state==2 && a[i]<a[i+1])
            dp[state][i] = 1;
        else if(state==1 && a[i]<=a[i+1])
            dp[state][i] = 1 + f(2, i+1);
        else if(state==2 && a[i]>=a[i+1])
            dp[state][i] = 1 + f(1, i+1);
        return dp[state][i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)
            cin >> a[i];
        for(i=0; i<1000005; i++)
        {
            dp[1][i] = -1;
            dp[2][i] = -1;
        }
        for(i=n; i>0; i--)
        {
            k = f(1, i);
            k = f(2, i);
        }
        int ans = -1;
        for(i=1; i<=n; i++)
        {
            k = dp[1][i];
            if(k+i>n)
                ans = max(ans, 1+k);
            else if(k%2==0)
                ans = max(ans, k+1+dp[2][i+k]);
            else if(k%2==1)
                ans = max(ans, k+1+dp[1][i+k]);
        }
        cout << ans << "\n";
    }
    return 0;
}
