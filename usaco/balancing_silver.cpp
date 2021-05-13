#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
vector<pair<int, int> > grid(1005);
int n;

int min_pts(int a1, int a2)
{
    int t1=0, t2=0, t3=0, t4=0;
    for(int i=1; i<=n; i++)
    {
        if(grid[i].f>a1 && grid[i].s>a2)
            t1+=1;
        else if(grid[i].f>a1 && grid[i].s<a2)
            t4+=1;
        else if(grid[i].f<a1 && grid[i].s>a2)
            t2+=1;
        else if(grid[i].f<a1 && grid[i].s<a2)
            t3+=1;
    }
    return max(max(t1, t2), max(t3,t4));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int b;
    fin >> n;
    for(int i=1; i<=n; i++)
    {
        int x,y;
        fin >> x >> y;
        grid[i]=(mp(x,y));
    }
    /*cout << a1 << " " << a2 << "\n";
    for(int i=1; i<=n; i++)
        cout << grid[i].f << " " << grid[i].s << endl;*/
    int ans = 1000000;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            ans = min(ans, min_pts(grid[i].f+1, grid[j].s+1));
        }
    }
    fout << ans << "\n";
    return 0;
}
