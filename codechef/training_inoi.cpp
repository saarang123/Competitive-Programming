#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
ll n, a[5005], power[5005], dp[5005][5005];

int cube_sum(int a)
{
    int ret = 0;
    while(a>0)
    {
        ret+= a%10;
        a/=10;
    }
    return ret*ret*ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k,s;
    cin >> n >> s;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    power[1] = s;
    for(i=2; i<=n; i++)
        power[i] = power[i-1]+cube_sum(power[i-1]);
    for(i=1; i<=n; i++)
    {
        dp[i][n] = power[i]*a[n];
    }
    for(i=n; i>=1; i--)
    {
        for(j=n-1; j>=i; j--)
        {
            dp[i][j] = max(power[i]*a[j]+dp[i][j+1], dp[i+1][j+1]);
        }
    }
    /*
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    */
    cout << dp[1][1] << "\n";
    return 0;
}
