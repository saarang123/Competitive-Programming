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

const int N = 1e4+3;
int a[N], dp[103][N] = {0};

int max3(int a, int b, int c)
{
    return max(max(a,b),c);
}

void sum(int dp[], int a[], int n)
{
    int m1 = -INF, m2 = 0;
    for (int i = 1; i<=n; i++)
    {
        m2 += a[i];
        if (m2 < 0)
            m2 = 0;
        if (m1<m2)
            m1=m2;
        dp[i] = m1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> k;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    sum(dp[0],a,n);  //Kadane's for K=0

    for(j=1; j<=k; j++)
    {
        for(i=1; i<=n; i++)
        {
            dp[j][i] = max3(0, dp[j-1][i-1], dp[j][i-1]+a[i]); //dp
        }
    }

    /*
    for(j=0; j<=k; j++)
    {
        cout << j << ": ";
        for(i=1; i<=n ;i++)
        {
            cout << dp[j][i] << " ";
        }
        cout << "\n";
    }
    */

    int ans = -1;
    for(i=1; i<=n; i++)
    {
        ans = max(ans, dp[k][i]); //ans
        //cout << dp[i][k] << " ";
    }
    cout << ans << "\n";
    return 0;
}
