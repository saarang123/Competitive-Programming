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
    int n,i,j,k,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int p[n];
        for(i=0; i<n; i++)
        {
            cin >> p[i];
            //cout << p[i];
        }
        for(i=0; i<n; i++)
        {
            int a[n];
            for(j=0; j<n; j++)
            {
                a[j] = p[j]-1;
                // << "\n";
            }
            int pres=i, ans = 1;
            while(a[pres]!=i)
            {
                pres = a[pres];
                ans++;
            }
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
