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

int dp[23][23] = {0}, grid[23][23] = {0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    char c;
    RE(i,n)
    {
        RE(j,n)
        {
            cin >> c;
            if(c=='E') grid[i][j] = 0;
            else grid[i][j] = 1;
            dp[i][j] = INF;
        }
    }
    dp[n][n] = 0;
    FO(i,n)
    {
        FO(j,n)
        {
            if(grid[i][j]) continue;
            if(i==n && j==n) continue;
            dp[i][j] = min(1+dp[i+1][j], 2+dp[i][j+1]);
        }
    }
    cout << dp[1][1] << "\n";
    return 0;
}
