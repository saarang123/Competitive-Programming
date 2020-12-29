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

const int N = 5e3+3;
vector<int> a = {-1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> n;

    RE(i,n)
    {
        cin >> j;
        if(j==a.back()) continue;
        a.pb(j);
    }

    n = a.size()-1;
    vector<int> rev = a;

    cout << "\n";
    RE(i,n)
    {
        RE(j,n)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";


    int ans = dp[1][n];
    cout << ans << "\n";
    return 0;
}
