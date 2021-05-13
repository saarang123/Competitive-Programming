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
    3d dp[i][j][k]: gives the minimum cost to colour the first i trees such that i'th trees colour is j
    and beauty is k.
*/

ll p[105][105],c[105], dp[105][105][105]={0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,d;
    cin >> n >> m >> d;
    RE(i,n)
    {
        cin >> c[i];
    }
    RE(i,n)
    {
        RE(j,m)
        {
            cin >> p[i][j];
        }
    }
    REP(i,0,n)
    {
        REP(j,0,m)
        {
            REP(k,0,d)
            {
                dp[i][j][k] = 1e12;
            }
        }
    }

    if(c[1]!=0)
    {
        dp[1][c[1]][1] = 0;
    }
    else
    {
        RE(i,m)
        {
            dp[1][i][1] = p[1][i];
        }
    }


    RE(i,n)
    {
        RE(k,d)
        {
            RE(j,m)
            {
                if(c[i]!=0)
                {
                    dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i-1][c[i]][k]);
                    RE(t,m)
                    {
                        if(c[i]==t) continue;
                        dp[i][c[i]][k] = min(dp[i][c[i]][k], dp[i-1][t][k-1]);
                    }
                    continue;
                }
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+p[i][j]);
                RE(t,m)
                {
                    if(j==t) continue;
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][t][k-1]+p[i][j]);
                }
            }
        }
    }

    /*
    RE(i,n)
    {
        RE(j,m)
        {
            REP(k,1,d)
            {
                cout << dp[i][j][k] << ",";
            }
            cout << "  |  ";
        }
        cout << "\n";
    }
    cout << "\n";
    */

    ll ans=1e12;
    RE(i,m)
    {
        ans = min(ans, dp[n][i][d]);
    }
    if(ans>=1e12)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}
