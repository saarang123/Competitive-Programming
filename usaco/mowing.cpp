#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;

int mow[2005][2005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    //freopen("input.txt", "r", stdin);
    memset(mow, -1, sizeof mow);
    int n,s, i, j;
    char d;
    int answer = 1001;
    fin >> n;
    int t = 0;
    int x = 1000, y = 1000;
    for(i=0; i<n; i++)
    {
        fin >> d >> s;
        for(j=0; j<s; j++)
        {
            t++;
            if(mow[x][y]>=0 && t-mow[x][y]<answer)
            {
                answer = t-mow[x][y];
            }
            mow[x][y] = t;
            if(d=='N')
                x++;
            else if(d=='S')
                x--;
            else if(d=='E')
                y++;
            else if(d=='W')
                y--;
        }
    }
    if(answer==1001)
        fout << -1 << "\n";
    else
        fout << answer << "\n";
    return 0;
}
