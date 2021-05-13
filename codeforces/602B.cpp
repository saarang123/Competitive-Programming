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

const int N = 1e5+2;
int a[N], dp[N]={0};
pii m1,m2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;
    RE(i,n)
    {
        cin >> a[i];
    }
    dp[1] = 1;
    //m1 = mp(a[1],1);
    //m2 = mp(a[1],1);
    j=a[1];
    k=a[1];
    REP(i,2,n)
    {
        if(a[i]>=j)
        {
            //m1 = mp(a[i],i);
            j=a[i];

        }
        else if(a[i]<=k)
        {
            //m2 = mp(a[i],i);
            k = a[i];
        }
        if(j-k<=1)
        {
            dp[i] = 1+dp[i-1];
        }
        else
        {
            //m1 = mp(a[i],i);
            //m2 = mp(a[i],i);
            dp[i] = 1;
        }
    }
    int ans = -1;
    RE(i,n)
    {
        cout << dp[i] << " ";
        ans = max(ans, dp[i]);
    }
    cout << "\n";
    cout << ans << "\n";
    return 0;
}
