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
    ifstream fin("gates.in");
    ofstream fout("gates.out");

    set<pair<int, int> > grid;
    int n;
    int x = 1001, y = 1001, i, j, gates=0;

    cin >> n;
    int flag = 0;
    for(i=0; i<n; i++)
    {
        char c;
        cin >> c;
        if(grid.count(mp(x,y)) && flag)
        {
            gates+=1;
            flag = 0;
        }
        else
        {
            grid.insert(mp(x,y));
            flag=1;
        }

        if(c=='N')i
            x++;
        else if(c=='S')
            x--;
        else if(c=='E')
            y++;
        else
            y--;
    }
    c << gates << "\n";
    return 0;
}
