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
    int i,j,n,t;
    cin >> n;
    int a[n+1];
    a[1] = 1;
    j = 4;
    for(i=2; i<=n; i++)
    {
        a[i] = a[i-1] + j;
        j+=4;
    }
    cout << a[n] << "\n";
    return 0;
}
