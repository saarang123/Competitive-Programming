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
    int i,j, t, n, x, y,a,b;
    ll k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int p[n+1], k;
        int s[n+1];
        memset(s, 0, sizeof s);
        for(i=1; i<=n; i++)
            cin >> p[i];
        cin >> x >> a >> y >> b >> k;
        sort(p, p+n+1, greater<int>());
        j=max(a,b);i=1;

        while(j<=(n+1))
        {
            s[j] = p[i];
            i++;
            j+=max(a,b);
        }

        i--;
        j = min(a,b);
        while(j<=(n+1))
        {
            if(s[j]==0)
            {
                s[j] = p[i];
                i++;
            }
            j+=min(a,b);
        }
        i--;

        for(j=1; j<=n; j++)
        {
            if(s[j]==0)
            {
                s[j]=p[i];
                i++;
            }
        }


        int ans = 0;
        for(i=1; i<=n; i++)
        {
            if(i%a==0 && i%b==0)
                ans+= s[i] * (x+y) / 100;
            else if(i%a==0)
                ans+= s[i] * x/100;
            else if(i%b==0)
                ans+= s[i]*y/100;
            if(ans>=k)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
