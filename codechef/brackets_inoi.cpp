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
ll v[705], b[705], dp[705][705]={0};

/*
    2D DP soln: dp[i][j]
    dp[i][j] represents the maximum sum of values possible for matched brackets
    inside.
    dp[i][j] =  v[i]+v[j] + dp[i+1][j-1]  if(v[j]==v[i]+k)  #They matched
                max(dp[i+1][j],dp[i][j-1])  else           #dont match
    We fill the dp matrix with the above recurrences. This gives us the maximum
    sum of values of matched brackets inside.
    Note: We can also combine different sets of matched brackets which is not
    checked in the above recurrences.
    Therefore we also modify all dp[i][j] = max(dp[i][j], dp[i][m]+dp[m+1][j])
    for i<=m<=j. This checks for combination of matched brackets.
    We can now return dp[1][n] which will be our solution.
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n >> k;

    RE(i,n+2)
    {
        RE(j,n+2)
        {
            dp[i][j] = 0;  //making elements 0
        }
    }

    RE(i,n)
    {
        cin >> v[i];
    }
    RE(i,n)
    {
        cin >> b[i];
    }

    FO(i,n)
    {
        REP(j,i,n)
        {
            if(i==j)
            {
                dp[i][j] = 0;  //if i==j
                continue;
            }
            if(b[j] == b[i]+k)
            {
                dp[i][j] = v[i]+v[j]+ dp[i+1][j-1];  //if they form matched pair
            }
            else
            {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);  //if not matched pair
            }
            REP(m,i,j)
            {
                dp[i][j] = max(dp[i][j], dp[i][m] + dp[m+1][j]);
                //checking all combination of matched brackets also
            }
        }
    }
    cout << dp[1][n] << "\n";   //the answer :)
    /*
    RE(i,n)
    {
        RE(j,n)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */
    return 0;
}
