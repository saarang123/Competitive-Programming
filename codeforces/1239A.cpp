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
    int a,b,c,d,k, t;
    cin >> t;
    while(t--)
    {

        cin >> a >> b >> c >> d >> k;
        int p1=0, p2=0;
        p1 = a/c;
        if(a%c>0)
            p1++;
        p2 = (b/d);
        if(b%d>0)
            p2++;
        if(p1+p2 <= k)
            cout << p1 << " " << p2 << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}
