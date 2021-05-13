#include <bits/stdc++.h>
using namespace std;

namespace{
    int dist[1025][1025];
    int n, hiddenVertex, asked;
}

int findHiddenVertex(int n, vector<int> parents);

int query(vector<int> V){
    const int INF = 1 << 30;
    if(V.empty()){
		cerr << "ERROR: The queried set can't be empty." << endl;
        assert(0);
        return 0;
    }
    vector<bool> came(n + 1, false);
    int sdist = INF, ldist = 0;
    for(int v : V){
        if(v <= 0 || v > n){
            cerr << "ERROR: The elements of the queried set must be in [1, n] inclusive" << endl;
            assert(0);
            return 0;
        }
        if(came[v]){
            cerr << "ERROR: The elements of the queried set must be distinct" << endl;
            assert(0);
            return 0;
        }
        came[v] = true;
        sdist = min(sdist, dist[hiddenVertex][v]);
        ldist = max(ldist, dist[hiddenVertex][v]);
    }
    cerr << "Query number: " << asked << " ";
    for(int v : V) cerr << v << ' ';
    cout << " returns: " << sdist + ldist << endl;
    asked++;
    return sdist + ldist;
}

int main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cerr << "Test " << tc << ":"<<endl;
        cin >> n >> hiddenVertex;
        assert(n <= 1024 && n >= 2);
        assert(hiddenVertex >= 1 && hiddenVertex <= n);
        asked = 0;
        const int INF = 1 << 30;
        vector<vector<int>> adj(n + 1);
        vector<int> p(n - 1);
        for(int i = 0; i < n - 1; i++){
            cin >> p[i];
            adj[p[i]].push_back(i + 2);
            adj[i + 2].push_back(p[i]);
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) dist[i][j] = INF;
            queue<int> q;
            q.push(i);
            dist[i][i] = 0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int v : adj[u]) if(dist[i][v] == INF){
                    dist[i][v] = dist[i][u] + 1;
                    q.push(v);
                }
            }
        }
        int output = findHiddenVertex(n, p);
        if(output != hiddenVertex){
            cerr << "expected " << hiddenVertex << ", got " << output << endl;
            assert(0);
        } else{
            cerr << "Correct!" << endl;
            cerr << "n = " << n << ", queries asked = " << asked << endl;
        }

        cerr << endl;
    }
}