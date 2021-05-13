#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    ll a[n], val[m] = {}, dp[n] = {};
    for(i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    for(i=1; i<=n; i++)
    {
        val[i%m] += a[i-1];
        dp[i] = dp[i-1] + val[i%m];
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}
