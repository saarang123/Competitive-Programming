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
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    //freopen("input.txt", "r", stdin);
    int x,y,m, i, j, ans;
    fin >> x >> y >> m;
    ans = 0;
    int a = m/x + 1;
    int b = m/y + 1;
    for(i=0; i<=a; i++)
    {
        for(j=0; j<=b; j++)
        {
            if(x*i + y*j <=m && x*i + y*j>ans)
                ans = x*i + y*j;
        }
    }
    fout << ans << "\n";
    return 0;
}
