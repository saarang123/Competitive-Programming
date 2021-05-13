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
    int n,i,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        k = INF;
        int ans = 1, j=0, l=0;
        int a[n], b[n];
        for(i=0; i<n; i++)
            cin >> a[i];
        for(i=0; i<n; i++)
            cin >> b[i];
        for(i=0; i<n; i++)
        {
            if(a[i]!=b[i])
            {
                if(j==1 && l==1)
                {
                    ans = 0;
                    break;
                }
                if(k==INF)
                {
                    k = b[i]-a[i];
                    j=1;
                    l=0;
                }
                if(b[i]-a[i]!=k)
                {
                    ans = 0;
                    break;
                }
                if(k<0)
                {
                    ans = 0;
                    break;
                }
            }
            else
            {
                l = 1;
            }
        }
        if(ans==1)
            cout << "YES\n";
        else
            cout << "NO\n";
        //cout << k << "\n";
    }
    return 0;
}
