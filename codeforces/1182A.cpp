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
    int n,i,j;
    cin >> n;
    int a[65];
    a[1] = 0;
    a[2] = 2;
    for(i=3; i<=n; i++)
    {
        a[i] = 2 * a[i-2];
    }
    cout << a[n] << "\n";
    return 0;
}
