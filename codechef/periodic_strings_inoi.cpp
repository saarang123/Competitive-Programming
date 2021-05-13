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
    Solution can be solved with dp or ad-hoc methods.
    I have used a dp.
    dp[i] = 2^i - dp[j] - dp[i/j]  for all j such that i%j==0 and i/j!=j (perfect squares).
*/

ll power[150005], ans[150005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> m;
    power[0] = 1;
    RE(i,n)
    {
        power[i] = (2 * power[i-1])%m; //finding powers
    }

    ans[1] = 2;
    REP(i,2,n)
    {
        ans[i] = power[i]%m;
        for(j=1; j*j<=i; j++)
        {
            if(i%j==0)
            {
                ans[i] = ((ans[i]-ans[j])%m + m)%m;  //factors
                if(j!=1 && i/j!=j)
                {
                    ans[i] = ((ans[i]-ans[i/j])%m + m)%m;  //again factors.
                }
            }
        }
    }

    /*
    RE(i,n)
        cout << ans[i] << " ";
    cout << "\n";
    */

    cout << ans[n]%m << "\n";
    return 0;
}
