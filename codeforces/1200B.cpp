#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
int h[105],n,m,k;

bool dp(int i, int m)
{
    if(i==n)
        return true;
    //cout << i << " " << m << " " << h[i] << " " << h[i+1] << "\n";
    if(h[i]>=h[i+1])
    {
        int h2 = max(h[i+1] - k,0);
        return dp(i+1, m+h[i]-h2);
    }
    else
    {
        if(abs(h[i+1]-h[i]) <= k)
        {
            int d = max(h[i+1]-k,0);
            return dp(i+1, m+h[i]-d);
        }
        else
        {
            int d = max(h[i+1] - k,0);
            if(d-h[i] <= m)
                return dp(i+1, m -(d-h[i]));
            else
                return false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int i,j,t;
    cin >> t;
    //cout << "\n";
    while(t--)
    {
        cin >> n >> m >> k;
        for(i=1; i<=n; i++)
            cin >> h[i];
        bool ans = dp(1, m);
        //cout << n << ":" << m << "\n";
        if(ans)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
