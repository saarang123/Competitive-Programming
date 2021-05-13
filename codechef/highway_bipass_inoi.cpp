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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
ll dp[305][305][3][305] = {0};

/*
    DP Soln:
    Keeping 3d DP matrix of [R][C][D].
    The dp[i][j][k] will store number of paths from (i,j) to (r,c) that have just
    completed k continuous up/side movements.
    dp[i][j][1][k] means the number of movements that go side.
    dp[i][j][2][k] means number of movements going bottom.
    Space Complexity: O(R*C*D) ~ O(N^3)
    Time Complexity: O(R*C*D) ~ O(N^3)
*/


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,d,j,t,k,m;
    cin >> n >> m >> d;
    bool grid[n+1][m+1];
    dp[n][m][1][0] = 1;   //initializing the end point has 1 path with 0 continuous movements.
    dp[n][m][2][0] = 1;   //initializing the end point has 1 path with 0 continuous movements.
    RE(i,n)
    {
        RE(j,m)
        {
            cin >> grid[i][j];
        }
    }
    for(i=n; i>0; i--)
    {
        for(j=m; j>0; j--)
        {
            if(i==n && j==m) continue;
            if(!grid[i][j])  continue;

            REP(k, 1, d)
            {
                dp[i][j][1][k] = dp[i+1][j][1][k-1]%20011;
                //Paths with k-1 side movements move one more side and become k movements
                dp[i][j][1][1] += dp[i+1][j][2][k]%20011;
                //Paths which move bottom all become side paths of length 1
            }
            REP(k, 1, d)
            {
                dp[i][j][2][k] = dp[i][j+1][2][k-1]%20011;
                //Paths with k-1 bottom movements move one more bottom/up and become k movements
                dp[i][j][2][1] += dp[i][j+1][1][k]%20011;
                //Paths which move side all become bottom paths of length 1
            }
        }
    }
    /*
    RE(i,n)
    {
        RE(j,m)
        {
            cout << i << " " << j << ": ";
            REP(k,0,max(n,m))
            {
                cout << dp[i][j][1][k]+dp[i][j][2][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    */
    ll ans = 0;
    for(i=0; i<=d; i++)
    {
        ans+=dp[1][1][1][i]+dp[1][1][2][i]%20011;
        //summing up paths with <=k continuous movements
    }
    cout << ans%20011 << "\n";
    return 0;
}
