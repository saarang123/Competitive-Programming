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
    int n,i,j,t,k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(i=0; i<n; i++)
            cin >> a[i];
        sort(a, a+n);
        int c = 1;
        for(i=0; i<n-1; i++)
        {
            if(a[i+1]-a[i]==1)
                c = 2;
        }
        cout << c << "\n";
    }
    return 0;
}
