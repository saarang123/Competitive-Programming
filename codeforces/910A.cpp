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
    int n,i,j,t,d;
    cin >> n >> d;
    string s;
    cin >> s;
    int a[204];
    for(i=0; i<204; i++)
        a[i] = 1000000000;
    a[n] = 0;
    for(i=n-1; i>=1; i--)
    {
        if(s[i-1]=='1')
        {
            for(j=1; j<=d; j++)
            {
                a[i] = min(a[i], 1+a[i+j]);
            }
        }
    }
    if(a[1]>=1000000000)
        cout << -1 << "\n";
    else
        cout << a[1] << "\n";
    return 0;
}
