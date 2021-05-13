#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
#define setitr set <int, greater <int> > :: iterator
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[100005] = {0};
        for(i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        int ans = 0;
        for(i=0; i<n; i++)
        {
            if(i==0)
            {
                if(a[i+1]-a[i]!=1)
                {
                    ans++;
                    a[i]++;
                }
            }
            else if(i==n-1)
            {
                if(a[i]-a[i-1]!=1)
                {
                    ans++;
                    a[i]++;
                }
            }
            else
            {
                if(a[i]-a[i-1]!=1 && a[i+1]-a[i]!=1)
                {
                    ans++;
                    a[i]++;
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
