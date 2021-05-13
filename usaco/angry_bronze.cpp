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
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int i,j, n, c, r, p;
    fin >> n;
    int a[n+1];
    for(i=1; i<=n; i++)
        fin >> a[i];
    sort(a+1, a+n+1);
    /*for(i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;*/
    int max = 0;
    for(i=1; i<=n; i++)
    {
        c = 1;
        r = 1;
        p=i;
        for(j=i-1; j>0; j--)
        {
            if(!(a[p]-a[j] <= r))
                break;
            while(a[p]-a[j] <= r && j>0)
            {
                //cout << i << " " << p << " " << j << " " << a[j] << " " << a[p] << " " << r << "\n";
                c++;j--;
            }
            r++;j+=1;p=j;
        }
        r=1;
        p=i;
        for(j=i+1; j<=n; j++)
        {
            if(!(a[j]- a[p] <= r))
                break;
            while(a[j]- a[p] <= r && j<=n)
            {
                //cout << i << " " << p << " " << j << " " << a[j] << " " << a[p] << " " << r << "\n";
                c++;j++;
            }
            r++;j-=1;p=j;
        }
        if(max<c)
            max = c;
        //cout << c << "\n";
    }
    fout << max << "\n";
    return 0;
}
