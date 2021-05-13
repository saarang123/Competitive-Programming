#include<bits/stdc++.h>
using namespace std;
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

const int N = 2e5 + 5;
ll a[N], b[N], dp[N][3]={0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,c,k;
    cin >> n >> c;
    a[1]=0;
    b[1]=0;
    REP(i,2,n)
    {
        cin >> a[i];
    }
    REP(i,2,n)
    {
        cin >> b[i];
    }

    dp[1][1]=0;
    dp[1][2]=0;
    dp[2][1]=a[2];
    dp[2][2]=b[2]+c;

    REP(i,3,n)
    {
        dp[i][1] = min(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
        dp[i][2] = min(dp[i-1][1]+b[i]+c, dp[i-1][2]+b[i]);
    }

    RE(i,n)
    {
        cout << min(dp[i][1], dp[i][2]) << " ";
    }
    cout << "\n";
    return 0;
}
