#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
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
        int a[n];
        for(i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        int ans = -INF;
        for(i=0; i<n; i++)
        {
            if(a[i]>ans)
            {
                ans = max(ans, min(n-i, a[i]));
            }
            //cout << ans << " " ;
        }
        cout << ans << "\n";
    }
    return 0;
}
