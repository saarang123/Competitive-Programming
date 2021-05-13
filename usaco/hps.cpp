#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define se second
typedef long long ll;

int max_3(int a, int b, int c)
{
    return max(max(a,b),c);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    //freopen("input.txt", "r", stdin);
    int n,i,j;
    char ss;
    fin >> n;
    int h[n+1], p[n+1], s[n+1],m = 0;
    h[0]=0; s[0]=0; p[0]=0;
    for(i=1; i<=n; i++)
    {
        fin >> ss;
        if(ss=='P')
        {
            h[i]=h[i-1];
            p[i]=p[i-1]+1;
            s[i]=s[i-1];
        }
        else if(ss=='S')
        {
            h[i]=h[i-1];
            p[i]=p[i-1];
            s[i]=s[i-1]+1;
        }
        else
        {
            h[i]=h[i-1]+1;
            p[i]=p[i-1];
            s[i]=s[i-1];
        }

    }
    /*
    for(i=0; i<=n; i++)
            cout << h[i] << " ";
    cout << "\n";
    for(i=0; i<=n; i++)
        cout << p[i] << " ";
    cout << "\n";
    for(i=0; i<=n; i++)
        cout << s[i] << " ";
    cout << "\n";
    */

    for(int sub = 1; sub<=n; sub++)
        {
            int pres = max_3(p[sub], s[sub], h[sub]) + max_3(p[n]-p[sub], h[n]-h[sub], s[n]-s[sub]);
            //cout << pres << "\n";
            if(pres>m)
                m = pres;
        }
    fout << m << "\n";
    return 0;
}
