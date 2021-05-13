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
    int i,j,k,n,t, c=0;
    cin >> n >> t;
    int a[n];
    for(i=0; i<n; i++)
        cin >> a[i];

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            for(k=j+1; k<n; k++)
            {
                for(int l = k+1; l<n; l++)
                {
                    if(a[i]+a[j]+a[k]+a[l]==t)
                    {
                        c++;
                        //cout << a[i] << " " << a[j] << " " << a[k] << " " << a[l] << "  indexes: ";
                        //cout << i << " " << j << " " << k << " " << l << "\n";
                    }
                }
            }
        }
    }
    cout << c << "\n";
    return 0;
}
