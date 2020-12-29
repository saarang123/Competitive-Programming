#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
bool vis[105][105], reach[105][105], light[105][105];
vector<pair<int, int> > turnlight[105][105];
int n,m;

void dfs(int x, int y)
{
    if(x>n || y>n || x<1 || y<1) return;
    reach[x][y]=true;
    if(!light[x][y]) return;
    if(vis[x][y]) return;
    vis[x][y]=true;
    for(pair<int,int> ab : turnlight[x][y])
    {
        light[ab.f][ab.s] = true;
        if(reach[ab.f][ab.s] && !vis[ab.f][ab.s])
            dfs(ab.f, ab.s);
    }
    dfs(x+1,y); dfs(x,y+1); dfs(x-1,y); dfs(x,y-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ifstream fin("lightson.in");
	ofstream fout("lightson.out");
	int i, j;
	fin >> n >> m;
	for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            vis[i][j] = false;
            light[i][j] = false;
            reach[i][j] = false;
        }
    }
	light[1][1]=true;
	reach[1][1]=true;
	for(i=0;i<m;i++)
	{
	    int x,y,a,b;
	    fin>>x>>y>>a>>b;
	    turnlight[x][y].pb(mp(a, b));
	}
	dfs(1,1);
	int cnt=0;
	for(i=1; i<=n; i++)
	{
	    for(j=1; j<=n; j++)
	    {
	        cnt+=light[i][j];
	    }
	}
	fout << cnt << "\n";
    return 0;
}

