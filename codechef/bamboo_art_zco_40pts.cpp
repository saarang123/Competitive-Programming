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
    cin >> n;
    int a[n];
    for(i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    int ans = -1;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            int c = 2;
            int t = a[j] - a[i];
            int pres = a[j];
            for(k=j+1; k<n; k++)
            {
                if(a[k] - pres == t)
                {
                    c++;
                    pres = a[k];
                }
            }
            //cout << t << " " << c << "\n";
            ans = max(ans, c);
        }
    }
    cout << ans << "\n";
    return 0;
}
