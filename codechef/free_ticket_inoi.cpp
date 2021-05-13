#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
int v,e,p;
int graph[235][235];
int dist[235][235];

int min_dist()
{
    int i,j,k;
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for(i=0; i<v; i++) //intermidiate vertice
    {
        for(j=0; j<v; j++) //starting source
        {
            for(k=0; k<v; k++)  //destination vertice
            {
                if(dist[j][i]+dist[i][k] < dist[j][k] &&j!=k)
                    dist[j][k] = dist[j][i]+dist[i][k];
            }
        }
    }
    int ans = -INF;
    for(i=0; i<v; i++)
    {
        for(j=0; j<v; j++)
        {
            if(i==j) continue;
            ans = max(ans, dist[i][j]);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n,i,j,t,k;
    cin >>v >> e;
    for(i=0; i<235; i++)
    {
        for(j=0; j<235; j++)
        {
            graph[i][j] = INF;
        }
    }
    for(i=0; i<e; i++)
    {
        cin >> k >> t >> p;
        k--,t--;
        graph[k][t] = p;
        graph[t][k] = p;
    }
    cout << min_dist() << "\n";
    return 0;
}
