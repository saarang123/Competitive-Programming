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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        int k1,k2;
        cin >> n >> k1 >> k2;
        int m1 = 0, m2 = 0;
        RE(i,k1)
        {
            cin >> j;
            m1 = max(m1,j);
        }
        RE(i,k2)
        {
            cin >> j;
            m2 = max(m2,j);
        }
        if(m1>m2)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
