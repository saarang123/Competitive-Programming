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
    ll n,p,d,w, i, j, a1=-1, a2=-1, a3=-1;
    cin >> n >> p >> w >> d;
    ll l = min(p/d, p/w);
    ll a = p%d, b = w%d;
    for(i=0; i<d; i++)
    {
        if(a-((b*i)%d)==0)
        {
            a1 = i;
            a2 = (p-(w*i))/d;
            if(a1+a2<=n)
           {
                a3 = n-(a1+a2);
                break;
           }
           a1 = -1, a2=-1;
        }
    }
    if(a1==-1 || a2==-1 || a3==-1)
        cout << -1 << "\n";
    else
        cout << a1 << " "<<a2 <<" "<< a3 <<" "<< "\n";
    return 0;
}
