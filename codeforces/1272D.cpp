#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
#define RE(i,n) for(int i=1; i<=n; i++)
#define REP(i,j,n) for(int i=j; i<=n; i++)
#define REB(i,j,n) for(int i=j; i>=n; i--)
#define FO(i,n) for(int i=n; i>0; i--)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

/*
    @Author: Saarang Srinivasan
    Handle: saarang123 on all platforms.
*/

const int N = 2e5+5;
int a[N], dp[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n)
    {
        cin >> a[i];
    }
    dp[n] = 1;
    REB(i,n-1,1)
    {
        if(a[i]<a[i+1])
        {
            dp[i] = dp[i+1]+1;
        }
        else
            dp[i] = 1;
    }
    /*
    RE(i,n)
    {
        cout << dp[i] << " ";
    }
    cout << "\n";
    */

    int ans = 0;
    RE(i,n)
    {
        int x = dp[i];
        if(i+x<=n && a[i+x]>a[i+x-2])
        {
            ans = max(ans, dp[i]-1+dp[i+x]);
        }
        if(i+x+1<=n && a[i+x-1]<a[i+x+1])
        {
            ans = max(ans, dp[i]+dp[i+x+1]);
        }
        else
        {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
