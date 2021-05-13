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
const int N = 1005;
int a[N],dp[N][N],n;
//dp[i][j] is solution for indices from i to n and having index j also left.
//out was the painful function which printed the order of customers out.

int min(int a, int b, int c)
{
    return min(a,min(b,c));
}


void out(int i, int j)
{
    if(i>n || j>i) return;
    if(i==n)
    {
        if(j==0) cout << n << "\n";
        else cout << n << " " << j << "\n";
        return;
    }
    if(i==n-1)
    {
        if(j==0)
        {
            cout << n-1 << " " << n << "\n";
        }
        else
        {
            if(dp[i][j]==max(a[j],a[n-1])+a[n])
            {
                cout << n-1 << " " << j << "\n";
                cout << n << "\n";
            }
            else if(dp[i][j]==max(a[n],a[n-1])+a[j])
            {
                cout << n-1 << " " << n << "\n";
                cout << j << "\n";
            }
            else
            {
                cout << j << " " << n << "\n";
                cout << n-1 << "\n";
            }
        }
        return;
    }
    if(i==n-2)
    {
        if(j==0)
        {
            out(i+1,i);
        }
        else
        {
            if(dp[i][j]==max(a[n-2],a[j])+dp[n-1][0])
            {
                cout << j << " " << n-2 << "\n";
                out(n-1,0);
            }
            else if(dp[i][j]==max(a[j],a[n-1])+dp[n][n-2])
            {
                cout << j << " " << n-1 << "\n";
                out(n,n-2);
            }
            else
            {
                cout << n-1 << " " << n-2 << "\n";
                out(n,j);
            }
        }
        return;
    }

    if(j==0)
    {
        if(dp[i][j]==max(a[i],a[i+1])+dp[i+2][0])
        {
            cout << i <<  " " << i+1 << "\n";
            out(i+2,0);
        }
        else if(dp[i][j]==max(a[i+1],a[i+2])+dp[i+3][i])
        {
            cout << i+1 << " " << i+2 << "\n";
            out(i+3,i);
        }
        else
        {
            cout << i << " " << i+2 << "\n";
            out(i+3,i+1);
        }
        return;
    }

    if(dp[i][j]==max(a[i],a[j])+dp[i+1][0])
    {
        cout << i << " " << j << "\n";
        out(i+1,0);
    }
    else if(dp[i][j]==max(a[i],a[i+1])+dp[i+2][j])
    {
        cout << i << " " << i+1 << "\n";
        out(i+2,j);
    }
    else
    {
        cout << j << " " << i+1 << "\n";
        out(i+2,i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t,k,m;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    if(n<=2)
    {
        if(n==1) cout << a[1] << "\n1\n";
        else cout << max(a[1],a[2]) << "\n1 2\n";
        return 0;
    }

    dp[n][0] = a[n];
    for(i=1; i<n; i++)
    {
        dp[n][i] = max(a[i],a[n]);
    }
    dp[n-1][0] = max(a[n-1],a[n]);
    for(i=1; i<n-1; i++)
    {
        dp[n-1][i] = min(max(a[i],a[n-1])+dp[n][0], max(a[n],a[n-1])+a[i], max(a[n],a[i])+a[n-1]);
    }
    dp[n-2][0] = min(max(a[n-1],a[n-2])+a[n], max(a[n-1],a[n])+a[n-2], max(a[n-2],a[n])+a[n-1]);
    for(i=1; i<n-2; i++)
    {
        dp[n-2][i] = min(max(a[n-2],a[i])+dp[n-1][0], max(a[i],a[n-1])+dp[n][n-2], max(a[n-2], a[n-1])+ dp[n][i]);
    }

    for(i=n-3; i>0; i--)
    {
        for(j=0; j<i; j++)
        {
            if(j==0)
            {
                dp[i][j] = min(max(a[i],a[i+1])+dp[i+2][0], max(a[i+1],a[i+2])+dp[i+3][i], max(a[i],a[i+2])+dp[i+3][i+1]);
                continue;
            }
            dp[i][j] = min(max(a[i],a[j])+dp[i+1][0], max(a[i],a[i+1])+dp[i+2][j], max(a[j],a[i+1])+dp[i+2][i]);
        }
    }

    /*
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */

    cout << dp[1][0] << "\n";
    out(1,0);
    return 0;
}
