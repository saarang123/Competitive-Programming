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

const int N = 104;
int dp[N][N][N][2];  //Index, odd, even, last
int a[N],f[N]={0},even=0,odd=0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n) f[i] = 0;
    RE(i,n)
    {
        cin >> j;
        f[j] = 1;
        if(j==0) a[i]=-1;
        else
        {
            a[i] = j%2;
        }
    }

    for(i=1; i<=n; i++)
    {
        if(!f[i])
        {
            if(i%2==0) even++;
            else odd++;
        }
    }

    for(i=0; i<=n; i++)
    {
        for(j=0; j<=even; j++)
        {
            for(k=0; k<=odd; k++)
            {
                dp[i][j][k][0] = INF;
                dp[i][j][k][1] = INF;
            }
        }
    }

    dp[0][0][0][1] = 0;
    dp[0][0][0][0] = 0;
    if(a[1]==-1)
    {
        dp[1][1][0][1] = 0;
        dp[1][0][1][0] = 0;
    }
    else if(!a[1])
    {
        dp[1][0][0][0] = 0;
    }
    else
    {
        dp[1][0][0][1] = 0;
    }

    //dp[i][j][k][0/1] is min complexity till i with j even elements, k odd elements, and last element is odd/even.
    for(i=2; i<=n; i++)
    {
        for(j=0; j<=even; j++)
        {
            for(k=0; k<=odd; k++)
            {
                if(a[i]==-1)
                {
                    if((j+k)>i) continue;
                    if(k>0)
                    {
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k-1][0]+1);
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k-1][1]);
                    }
                    if(j>0)
                    {
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i-1][j-1][k][1]+1);
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i-1][j-1][k][0]);
                    }
                }
                else
                {
                    if(a[i])
                    {
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k][1]);
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i-1][j][k][0]+1);
                        dp[i][j][k][0] = INF;
                    }
                    else
                    {
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i-1][j][k][0]);
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i-1][j][k][1]+1);
                        dp[i][j][k][1] = INF;
                    }
                }
            }
        }
    }

    /*
    for(i=1; i<=n ;i++)
    {
        cout << i << ": \n";
        for(j=0; j<=even; j++)
        {
            for(k=0; k<=odd; k++)
            {
                cout << dp[i][j][k][0] << " " << dp[i][j][k][1] << "\n";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    */
    if(a[n]!=-1) cout << dp[n][even][odd][a[n]] << "\n";
    else cout << min(dp[n][even][odd][1], dp[n][even][odd][0]) << "\n";
    return 0;
}
