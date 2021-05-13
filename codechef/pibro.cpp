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
        cin >> n >> k;
        string s;
        cin >> s;
        int a[100005] = {0}, b[100005] = {0}, ans=0;

        for(i=n-1; i>=0; i--)
        {
            if(s[i]=='0')
                a[i] = 0;
            else
                a[i] = 1+a[i+1];
        }

        if(s[0]=='1')
            b[0] = 1;
        else
            b[0] = 0;

        for(i=1; i<n; i++)
        {
            if(s[i]=='0')
                b[i] = 0;
            else
                b[i] = 1+b[i-1];
        }

        /*
        for(i=0; i<n; i++)
            cout << a[i] << " " ;
        cout << "\n";
        for(i=0; i<n; i++)
            cout << b[i] << " ";
        cout << "\n";
        */

        for(i=0; i<=n-k; i++)
        {
            if(i==0)
            {
                ans = max(ans, k+a[i+k]);
                //cout << k+a[i+k] << " ";
            }
            else
            {
                ans = max(ans, b[i-1]+k+a[i+k]);
                //cout << b[i-1]+k+a[i+k] << " ";
            }
        }
        //cout << "\n";
        cout << ans << "\n";
    }
    return 0;
}
