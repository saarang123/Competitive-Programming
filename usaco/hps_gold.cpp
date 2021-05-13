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

const int N = 1e5+5;
int a[N], dp[N][23][4] = {0};

int rps(int a, int b)
{
    if(a==1 && b==3)
        return a;
    if(a==3 && b==1)
        return b;
    if(a==1 && b==2)
        return b;
    if(a==2 && b==1)
        return a;
    if(a==2 && b==3)
        return b;
    if(a==3 && b==2)
        return a;
    return 0;
}

int max(int a, int b, int c)
{
    return max(a,max(b,c));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    fin >> n >> k;
    char s;
    RE(i,n)
    {
        fin >> s;
        if(s=='H')
            a[i] = 1;
        else if(s=='P')
            a[i] = 2;
        else
            a[i] = 3;
    }

    dp[0][0][1] = 0;
    dp[0][0][2] = 0;
    dp[0][0][3] = 0;
    FO(i,n)
    {
        RE(j,3)
        {
            dp[i][0][j]=dp[i+1][0][j];
            if(rps(j,a[i])==j)
                dp[i][0][j]++;
        }
    }

    RE(j,k)
    {
        FO(i,n)
        {
            int c = 0;
            if(rps(1,a[i])==1)
                c = 1;
            dp[i][j][1] = max(dp[i+1][j][1]+c, dp[i][j-1][2], dp[i][j-1][3]);

            c = 0;
            if(rps(2,a[i])==2)
                c = 1;
            dp[i][j][2] = max(dp[i+1][j][2]+c, dp[i][j-1][1], dp[i][j-1][3]);

            c = 0;
            if(rps(3,a[i])==3)
                c = 1;
            dp[i][j][3] = max(dp[i+1][j][3]+c, dp[i][j-1][2], dp[i][j-1][1]);
        }
    }
    /*
    REP(j,0,k)
    {
        cout << j << ":\n";
        RE(t,3)
        {
            RE(i,n)
            {
                cout << dp[i][j][t] << " ";
            }
            cout << "\n";
        }
    }
    */

    fout << max(dp[1][k][1], dp[1][k][2], dp[1][k][3]) << "\n";

    return 0;
}
