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

const int N = 105;
int a[N] = {-1}, dp[N][N][N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("gangs.in");
    ofstream fout("gang.out");
    int n,i,j,t,k,m;
    cin >> n >> m;
    RE(i,m)
    {
        cin >> a[i];
    }

    return 0;
}
