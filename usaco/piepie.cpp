#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define INF 1000000000
 
int N,D;
int A[2*MAXN];
int B[2*MAXN];
int dist[2*MAXN];
 
struct cmpA
{
    bool operator()(int a,int b) const
    {
        return B[a]<B[b];
    }
};
 
struct cmpB
{
    bool operator()(int a,int b) const
    {
        return A[a]<A[b];
    }
};
 
multiset<int,cmpA> sA;
multiset<int,cmpB> sB;
 
int que[2*MAXN];
int cur,len;
 
int main()
{
    cin >> N >> D;
    for(int i=0;i<2*N;i++)
    {
        cin >> A[i] >> B[i];
        A[i] = -A[i], B[i] = -B[i];
        dist[i] = -1;
    }
    for(int i=0;i<N;i++)
    {
        if(B[i]==0)
            que[len++] = i, dist[i] = 1;
        else
            sA.insert(i);
        if(A[N+i]==0)
            que[len++] = N+i, dist[N+i] = 1;
        else
            sB.insert(N+i);
    }
    multiset<int,cmpA>::iterator itA;
    multiset<int,cmpB>::iterator itB;
    while(cur < len)
    {
        int i = que[cur];
        if(i < N)
        {
            while(1)
            {
                itB = sB.lower_bound(i);
                if(itB == sB.end() || A[*itB] > A[i]+D)
                    break;
                dist[*itB] = dist[i] + 1;
                que[len++] = *itB;
                sB.erase(itB);
            }
        }
        else
        {
            while(1)
            {
                itA = sA.lower_bound(i);
                if(itA == sA.end() || B[*itA] > B[i]+D)
                    break;
                dist[*itA] = dist[i] + 1;
                que[len++] = *itA;
                sA.erase(itA);
            }
        }
        cur++;
    }
    for(int i=0;i<N;i++) {
        assert(1 <= dist[i] && dist[i] <= 3);
        cout << dist[i] << '\n';
    }
}