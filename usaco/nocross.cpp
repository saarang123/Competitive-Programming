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

const int N = 1e3+3;
int a[N], b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    ifstream fin("nocross.in");
    ofstream fout("nocross.out");
    memset(a, INF, sizeof a);
    memset(b, INF, sizeof b);
    fin >> n;
    RE(i,n)
    {
        fin >> a[i];
    }
    RE(i,n)
    {
        fin >> b[i];
    }
    int pres,ans = -1;
    RE(k,n)
    {
        j = 1;
        pres = 0;
        REP(i,k,n)
        {
            while(abs(b[j]-a[i])>4 && j<=n)
            {
                j++;
            }
            if(abs(b[j]-a[i])<=4)
            {
                pres++;
                //fout << i << " " << j << "\n";
            }
            j++;
        }
        ans = max(ans, pres);
    }
    fout << ans << "\n";
    return 0;
}
