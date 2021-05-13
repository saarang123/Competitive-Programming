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
int a[1005][1005], dp1[1005][1005][25], dp2[1005][1005][25], pre[1005][1005]={0};


/*
    Author: Saarang Srinivasan
    Handle: saarang123 on all platforms.
    3D dp solution:
    N - Length, M - Breadth, P - Distance between the paths.
    dp1[i][j][k] is max prefix path possible from (i,j) to top using upto k up-and-left moves.
    dp2[i][j][k] is min prefix path possible from (i,j) to top using upto k up-and-left moves.
    dp1 includes the sum of no.s in the path while dp2 doesn't.
    https://ibb.co/MMTJFnK  : This is an example of what dp2 would do. If the red path is the minimum path,
    dp2 takes all the prefix sums excluding the path.
    https://ibb.co/D7DzpGX  : This is an example of what dp1 would do. If the green path is the max path,
    dp1 takes all the prefix sums including the path.
    Hence it is quite easy to notice, that max(dp2[N][j][P]-dp1[N][i][P]) would give the answer
    for all (j,i) such that j-i>k.
    We fill the dp matrix using standard recurrences.
    dp1[i][j][k] = pre[i][j] + max(dp1[i-1][j][k], dp1[i-1][j-1][k-1])
    dp2[i][j][k] = pre[i][j] - a[i][j] + max(dp2[i-1][j][k], dp2[i-1][j-1][k-1])
                where pre[i][j] is the prefix sum matrix.
    Space Complexity = O(N*M*P)
    Time Complexity = O(N*M*P)
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m,p;
    cin >> t;
    while(t--)
    {
        //input and prefix sums
        cin >> n >> m >> p;
        RE(i,n)
        {
            RE(j,m)
            {
                cin >> a[i][j];
                pre[i][j]=a[i][j]+pre[i][j-1];  //making prefix sum
            }
        }

        //filling dp
        RE(i,n)
        {
            RE(j,m)
            {
                REP(k,0,p)
                {
                    dp1[i][j][k] = pre[i][j];  //initial values
                    dp2[i][j][k] = pre[i][j]-a[i][j];
                    //if(i==1) continue;  //top row is always the same
                    if(!k)
                    {
                        //if k==0 or j==1, again no dp needed. Path has to go top.
                        dp1[i][j][k] += dp1[i-1][j][k];
                        dp2[i][j][k] += dp2[i-1][j][k];
                    }
                    else
                    {
                        //filling dp
                        dp1[i][j][k] += max(dp1[i-1][j][k], dp1[i-1][j-1][k-1]);
                        dp2[i][j][k] += min(dp2[i-1][j][k], dp2[i-1][j-1][k-1]);
                    }
                }
            }
        }

        /*
        RE(i,n)
        {
            RE(j,m)
            {
                REP(k,0,p)
                {
                    cout << dp1[i][j][k] << ",";
                }
                cout << "  |  ";
            }
            cout << "\n";
        }
        cout << "\n";
        RE(i,n)
        {
            RE(j,m)
            {
                REP(k,0,p)
                {
                    cout << dp2[i][j][k] << ",";
                }
                cout << "  |  ";
            }
            cout << "\n";
        }
        cout << "\n";
        */

        //finding answer
        int ans = -INF;
        RE(i,m)
        {
            REP(j,i+1, m)
            {
                if(j-i<=p) continue;  //ensuring difference is >p between paths
                int pres = dp1[n][j][p]-dp2[n][i][p];
                ans = max(pres, ans);  //computing max
            }
        }
        cout << ans << "\n";

    }
    return 0;
}
