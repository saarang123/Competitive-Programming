#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
#define MOD 100000007
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
    3D dp[i][j][k] solution
    dp[i][j][k][1] gives no. of interleavings with first i elements of A, first j elements of B,
    that have k blocks such that the last element of all interleavings is A[i].
    dp[i][j][k][2] gives no. of interleavings with first i elements of A, first j elements of B,
    that have k blocks such that the last element of all interleavings is B[j].
*/

const int N = 103;
ll a[N], b[N], dp[N][N][2*N][3]={0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,d,p;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> d;
        a[0] = -1;
        b[0] = -1;
        RE(i,n)
        {
            cin >> a[i];
        }
        RE(i,m)
        {
            cin >> b[i];
        }
        REP(i,0,n)
        {
            REP(j,0,m)
            {
                REP(k,0,d)
                {
                    dp[i][j][k][1] = 0;
                    dp[i][j][k][2] = 0;
                }
            }
        }
        dp[0][1][1][2] = 1;
        dp[1][0][1][1] = 1;
        REP(i,2,n)
        {
            RE(k,d)
            {
                if(a[i]==a[i-1]) dp[i][0][k][1] += dp[i-1][0][k][1]%MOD;
                else dp[i][0][k][1] += dp[i-1][0][k-1][1]%MOD;

                if(b[i]==b[i-1]) dp[0][i][k][2] += dp[0][i-1][k][2]%MOD;
                else dp[0][i][k][2] += dp[0][i-1][k-1][2]%MOD;
            }
        }

        REP(i,1,n)
        {
            REP(j,1,m)
            {
                REP(k,1,d)
                {
                    if(k>i+j)
                    {
                        dp[i][j][k][1] = 0;
                        dp[i][j][k][2] = 0;
                        continue;
                    }
                    if(a[i]==a[i-1])
                    {
                        dp[i][j][k][1] += dp[i-1][j][k][1]%MOD;
                    }
                    else
                    {
                        dp[i][j][k][1] += dp[i-1][j][k-1][1]%MOD;
                    }
                    if(b[j]==b[j-1])
                    {
                        dp[i][j][k][2] += dp[i][j-1][k][2]%MOD;
                    }
                    else
                    {
                        dp[i][j][k][2] += dp[i][j-1][k-1][2]%MOD;
                    }

                    if(a[i]==b[j])
                    {
                        dp[i][j][k][2] += dp[i][j-1][k][1]%MOD;
                        dp[i][j][k][1] += dp[i-1][j][k][2]%MOD;
                    }
                    else
                    {
                        dp[i][j][k][2] += dp[i][j-1][k-1][1]%MOD;
                        dp[i][j][k][1] += dp[i-1][j][k-1][2]%MOD;
                    }
                    dp[i][j][k][1] = dp[i][j][k][1]%MOD;
                    dp[i][j][k][2]  = dp[i][j][k][2]%MOD;
                }
            }
        }

        /*
        REP(i,0,n)
        {
            REP(j,0,m)
            {
                cout << i << " " << j << " 1: ";
                RE(k,d)
                {
                    cout << dp[i][j][k][1] << " ";
                }
                cout << "\n";
                cout << i << " " << j << " 2: ";
                RE(k,d)
                {
                    cout << dp[i][j][k][2] << " ";
                }
                cout << "\n";
            }
        }
        */

        cout << (dp[n][m][d][1]+dp[n][m][d][2])%MOD << "\n";
    }
    return 0;
}
