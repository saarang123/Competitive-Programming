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
        int ans = 0;
        cin >> n;
        k = INF+1;
        int a[n];
        for(i=0; i<n; i++)
        {
            cin >> a[i] >> j;
            k = min(j, k);
        }
        for(i=0; i<n; i++)
        {
            if(a[i]>k)
            {
                ans+=a[i]-k;
                k = a[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
