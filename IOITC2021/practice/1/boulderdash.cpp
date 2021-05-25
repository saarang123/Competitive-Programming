#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000 * 100 + 3;
int n, q, mn[mxn], root;
vector<vector<int>> g;
vector<int> seq, tin;
int up[mxn][19], depth[mxn];
 
void dfs(int u, int d){
    depth[u] = d;
    if(u == root) for(int i = 0; i < 18; ++i) up[u][i] = u;
    else for(int i = 1; i < 18; ++i)  up[u][i] = up[up[u][i - 1]][i - 1];
    mn[u] = u;
    for(int v : g[u]){
        dfs(v, d + 1);
        mn[u] = min(mn[u], mn[v]);
    }
}
 
void dfs1(int u){
    vector<pair<int, int>> vs;
    for(int v : g[u]){
        vs.emplace_back(mn[v], v);
    }
    sort(vs.begin(), vs.end());
    for(auto v : vs) {
        dfs1(v.second);
    }
    tin[u] = seq.size();
    seq.push_back(u);
}
 
signed main(){
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> up[i][0], --up[i][0];
    g.resize(n);
    for(int i = 0; i < n; ++i){
        if(up[i][0] == -1) root = i;
        else g[up[i][0]].push_back(i);
    }
    dfs(root, 0);
    tin.resize(n);
    dfs1(root);
  
    set<int> rem;
    for(int i=0; i<n; ++i) rem.emplace(i);
    int type, k;
    while(q--){
        cin >> type >> k;
        int ans = 0;
        if(type == 1){
            for(int i = 0; i < k; ++i){
                ans = seq[*rem.begin()];
                rem.erase(rem.begin());
            }
            cout << ans + 1 << '\n';
        }else{
            --k;
            int start = k;
            for(int i = 17; i >= 0; --i){
                while(up[k][i] != k && rem.find(tin[up[k][i]]) == rem.end()) k = up[k][i];
            }
            rem.insert(tin[k]);
            cout << depth[start] - depth[k] << '\n';
        }
    }
}