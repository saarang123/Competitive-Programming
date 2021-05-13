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
    int i,j,n,a,b,c;
    cin >> n >> a >> b >> c;
    int m = min(a,min(b,c));
    int arr[4005];
    arr[0] = 0;
    for(i=1; i<=4005; i++)
    {
        arr[i] = -1000000000;
    }
    arr[m] = 1;
    for(i=m+1; i<=n; i++)
    {
        int d = i-a, e = i-b, c = i-c;

    }
    for(int i=1; i<=n; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
