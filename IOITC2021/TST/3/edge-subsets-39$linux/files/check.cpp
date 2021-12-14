#include "testlib.h"
#include <sstream>

using namespace std;

int main(int argc, char * argv[])
{
    setName("compare ordered sequences of signed int%d numbers", 8 * int(sizeof(long long)));

    registerTestlibCmd(argc, argv);

    int tt = inf.readInt();
    string firstElems;
    int t;
    for(t=1; t<=tt;t++)
    {
        setTestCase(t);
        if(ans.seekEof()){
            quitf(_wa, "jury ans not found");
        }
        if(ouf.seekEof()){
            quitf(_wa, "participant ans not found");
        }
        int n = inf.readInt();
        int m = inf.readInt();

        int par[n+1];
        for(int i = 2; i <= n; i++)
            par[i] = inf.readInt();

        vector<vector<int>> conditions;
        for(int i = 0; i < m; i++){
            int u = inf.readInt();
            int v = inf.readInt();
            int l = inf.readInt();
            int r = inf.readInt();
            conditions.push_back({u,v,l,r});
        }

        long long j = ans.readLong();
        long long p = ouf.readLong();
        if ((j == -1 and p != -1) or (j != -1 and p == -1))
            quitf(_wa, "test case %d differs", t);
        else{
            if(j == -1)
                continue;
            for(int i = 0; i < j; i++){
                long long vj = ans.readLong();
            }
            map<int, bool> nodes;
            for(int i = 0; i < p; i++){
                long long vc = ouf.readLong();
                nodes[vc] = 1;
            }
            for(auto c: conditions){
                int u = c[0], v = c[1];
                int l = c[2], r = c[3];
                int cnt = 0;
                while(v != u){
                    if(nodes[v])
                        cnt++;
                    v = par[v];
                }
                if(l <= cnt and cnt <= r)
                    continue;
                else
                    quitf(_wa, "one of condition failed");
            }
        }
    }

    int extraInAnsCount = 0;

    while (!ans.seekEof())
    {
        ans.readLong();
        extraInAnsCount++;
    }
    
    int extraInOufCount = 0;

    while (!ouf.seekEof())
    {
        ouf.readLong();
        extraInOufCount++;
    }

    if (extraInAnsCount > 0)
        quitf(_wa, "Answer contains longer sequence, but output contains less elements");
    
    if (extraInOufCount > 0)
        quitf(_wa, "Output contains longer sequence, but answer contains less elements");
    
    quitf(_ok, "all tests passed");
}
