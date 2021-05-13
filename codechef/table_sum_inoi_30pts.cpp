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
    int n,i,j,t,m,k;
    cin >> n;
    int a[n+1], sol[n+1];
    for(i=1; i<=n; i++)
        sol[i] = -INF;
    for(i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    for(i=n; i>0; i--)
    {
        k=n;j=i;m = 1;
        for(t=1; t<=n; t++)
        {
            if(j<1)
                j = n - j;
            sol[i] = max(sol[i], a[j]+k);
            //cout << j << " " << k << " " << sol[i] << "\n";
            k--;
            j--;
        }

        //cout << "\n";
    }
    for(i=n; i>0; i--)
        cout << sol[i] << " ";
    cout << "\n";
    return 0;
}
