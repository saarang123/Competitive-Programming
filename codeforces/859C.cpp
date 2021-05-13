#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1e9 + 7
#define INF 1e9
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k, a[55], pref[55], dp[55];
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
        pref[i] = a[i];
    }
    for(i=n-1; i>=0; i--)
    {
        pref[i]+=pref[i+1];
    }
    dp[n] = a[n];
    for(i=n-1; i>=0; i--)
    {
        dp[i] = max(dp[i+1], a[i]+pref[i+1]-dp[i+1]);
    }
    cout << pref[1]-dp[1] << " " << dp[1] << "\n";
    return 0;
}
