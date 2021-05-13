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
    ll n,i,j,t,k;
    cin >> n;
    k = sqrt(n);
    set<int> f;
    t = 1000000000005;
    for(i=2; i<=k; i++)
    {
        if(n%i==0)
        {
            if(n/i!=1)
            {
                t = min(t, n/i);
                f.insert(n/i);
            }
            t = min(t, i);
            f.insert(i);
        }
    }
    for(int el:f)
        cout << el << " ";
    cout << "\n";

    int a[k+1], cnt=0;
    for(i=0; i<=k; i++)
        a[i] = -1;
    a[1] = 1;
    for(i=2; i<=k; i++)
    {
        for(int el: f)
        {
            if((i+el)%k<=i)
            {
                if(a[(i+el)%k]!=-1)
                    a[i] = a[(i+el)%k];
                else
                {
                    cnt++;
                    a[i] = cnt;
                }
            }
        }
    }
    for(i=1; i<=k; i++)
        cout << a[i] << " ";
    cout << "\n";
    if(t==1000000000005)
        cout << n << "\n";
    else if(cnt==0)
        cout << 1 << "\n";
    else
        cout << cnt << "\n";
    return 0;
}
