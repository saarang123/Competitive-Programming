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
    cin >> n >> k;
    int a[n+1], back[n+1], front[n+1];
    a[0] = -INF;
    for(i=1; i<=n; i++)
        cin >> a[i];
    back[1] = 0;
    back[2] = a[1];
    for(i=3; i<=n; i++)
    {
        back[i] = max(a[i-1]+back[i-1], a[i-2]+back[i-2]);
    }
    front[n] = back[n];
    for(i=n-1; i>=1; i--)
    {
        if(i==n-1)
        {
            front[n-1] = max(a[n]+front[n], back[n-1]);
        }
        else
        {
            front[i] = max(a[i+1]+front[i+1], a[i+2]+front[i+2]);
            front[i] = max(front[i], back[i]);
        }
    }
    /*
    for(i=1; i<=n; i++)
    {
        cout << back[i] << " ";
    }
    cout << "\n";
    for(i=1; i<=n; i++)
    {
        cout << front[i] << " ";
    }
    cout << "\n";
    */
    cout << front[k] << "\n";
    return 0;
}
