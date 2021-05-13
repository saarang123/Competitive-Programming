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
    int n,i,j,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n<=2)
            cout << 4-n << "\n";
        else if(n%2==1)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
