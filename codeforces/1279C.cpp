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
*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k,m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        map<int, int> pres;
        int a[n+1], b[n+1];
        RE(i,n)
        {
            cin >> a[i];
            pres[a[i]]=i;
        }
        RE(i,m)
        {
            cin >> b[i];
        }

        ll ans=0, ab=0,j=0;
        REP(i,1,m)
        {
            if(pres[b[i]]<ab)
            {
                //cout << b[i] << "\n";
                ans++;
                j++;
                continue;
            }
            ab = pres[b[i]];
            ans += 2*(ab-i)+1;
            //cout << b[i] << " " << ab << " " << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}
