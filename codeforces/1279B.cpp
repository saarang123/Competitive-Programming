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
    int n,i,j,t,k,m,s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        ll a[n+1];
        RE(i,n)
        {
            cin >> a[i];
        }
        ll sum=0,skip=0,ans=0,msum=0;
        RE(i,n)
        {
            sum+=a[i];
            if(sum>s)
            {
                skip=i;
                ans=i-1;
                msum=i-1;
                sum-=a[i];
                j=i;
                break;
            }
            else if(sum==s)
            {
                skip = i;
                ans = i;
                msum = i;
                sum-=a[i];
                j=i;
                break;
            }
        }
        REP(i,j+1,n)
        {
            sum+=a[i];
            msum++;
            if(sum>s)
            {
                if(msum-1<ans)
                {
                    skip = 0;
                }
            }
            else if(sum==s)
            {
                if(msum<ans)
                {
                    skip = 0;
                }
            }
        }
        cout << skip << "\n";
    }
    return 0;
}
