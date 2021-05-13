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
    cin >> n;
    int a[n];
    for(i=0; i<n; i++) cin >> a[i];
    ll ans = 0, z=0, ne=0;
    for(i=0; i<n; i++)
    {
        if(a[i]<0)
        {
            ans += -1-a[i];
            ne++;
        }
        if(a[i]>0)
        {
            ans+= a[i]-1;
        }
        if(a[i]==0)
        {
            ans++;
            z =1;
        }
    }
    if(ne%2==0 || z)
    {
        cout << ans << "\n";
    }
    else
    {
        cout << ans + 2 << "\n";
    }
    return 0;
}
