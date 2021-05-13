#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
int dp[200005];
int p[200005];
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int q,h, i, j;
    cin >> q;
    while(q--)
    {
        cin >> h >> n;
        for(i=1; i<=n; i++)
            cin >> p[i];

        for(i=0; i<=200005; i++)
            dp[i] = 1000000002;
        dp[n] = 0;
        for(i=n-1; i>=1; i--)
        {
            if(p[i] - p[i+2]==2)
                dp[i] = min(1+dp[i+1], dp[i+2]);
            else if(p[i] - p[i+1]>2)
                dp[i] = min(dp[i+1], dp[i+2]);
            else if(p[i]-p[i+1]==2)
                dp[i] = min(1+dp[i+1], dp[i+2]);
            else if(p[i] - p[i+1]==1)
                dp[i] = 1 + min(dp[i+1], dp[i+2]);
        }
        for(i=1; i<=n; i++)
            cout << dp[i] << " ";
        cout << dp[1] << "\n";
    }
    return 0;
}
