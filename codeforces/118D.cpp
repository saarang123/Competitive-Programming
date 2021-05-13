#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define ss second
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

const int mod = 1e8;
const int N = 103;
ll dp[N][N][13][13] = {0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k1,k,l,k2,m;
    cin >> n >> m >> k1 >> k2;

    for(i=0; i<=k1; i++)
    {
        for(j=0; j<=k2; j++)
        {
            dp[0][0][i][j] = 1;
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=m; j++)
        {
            for(k=0; k<=k1; k++)
            {
                for(l=0; l<=k2; l++)
                {
                    if(i==0 && j==0) continue;
                    if(k>0 && i>0)
                    {
                        dp[i][j][k][l] += dp[i-1][j][k-1][k2]%mod;
                    }
                    if(l>0 && j>0)
                    {
                        dp[i][j][k][l] += dp[i][j-1][k1][l-1]%mod;
                    }
                }
            }
        }
    }
    cout << dp[n][m][k1][k2]%mod << "\n";
    return 0;
}
