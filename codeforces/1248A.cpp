#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ll i,j,n,m,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll o1=0,o2=0,e1=0,e2=0;
        for(i=0; i<n; i++)
        {
            cin >> j;
            if(j%2==0)
                e1++;
            else
                o1++;
        }
        cin >> m;
        for(i=0; i<m; i++)
        {
            cin >> j;
            if(j%2==0)
                e2++;
            else
                o2++;
        }
        ll ans = (o2*o1) + (e1*e2);
        cout << ans << "\n";
    }
    return 0;
}
