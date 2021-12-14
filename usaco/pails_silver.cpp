#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fin cin
#define fout cout
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    // ifstream fin("pails.in");
    // ofstream fout("pails.out");
    int x,y,k,m,i,j;
    fin >> x >> y >> k >> m;
    bool nex[x+1][y+1];
    for(i=0; i<=x; i++)
    {
        for(j=0; j<=y; j++)
        {
            nex[i][j] = false;
        }
    }
    nex[0][0]=true;
    for(int op = 0; op<k; op++)
    {
        bool can[x+1][y+1];
        /*
        Use of another table 'can' is to ensure operations aren't performed twice in the same loop of op.
        If u make some nex[i][j] true in the loop. If you apply an operation on nex[i][j] later in the same iteration of op, it is wrong. It must happen in the next iteration of op. Hence table can is used.
        */
        for(i=0; i<=x; i++)
        {
            for(j=0; j<=y; j++)
            {
                can[i][j] = false;
            }
        }
        for(i=0; i<=x; i++)
        {
            for(j=0; j<=y; j++)
            {
                if(!nex[i][j]) continue;
                can[i][j] = true;
                can[i][0]=true;
                can[0][j]=true;
                can[x][j]=true;
                can[i][y]=true;
                int  p = min(i, y-j);
                can[i-p][j+p] = true;
                int q = min(j, x-i);
                can[i+q][j-q] = true;
            }
        }
        for(i=0; i<=x; i++)
        {
            for(j=0; j<=y; j++)
            {
                nex[i][j] = can[i][j];
            }
        }
    }
    int res = 1000000000;
    for(i=0; i<=x; i++)
    {
        for(j=0; j<=y; j++)
        {
            //cout << nex[i][j] << " ";
            if(nex[i][j])
                res = min(res, abs(m-(i+j)));
        }
        //cout << "\n";
    }
    fout << res << "\n";
    return 0;
}
