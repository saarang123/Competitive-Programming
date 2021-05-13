#include <bits/stdc++.h>
using namespace std;
const int mxn = 1000 * 100 + 3;
int n, q, subMin[mxn], root;
vector<vector<int>> g;
vector<int> seq, ind_in_seq;
int up[mxn][19], depth[mxn];
 
void dfs0(int u, int d){
    depth[u] = d;
    if(u==root) for(int i=0; i<18; ++i) up[u][i] = u;
    else for(int i=1; i<18; ++i)  up[u][i] = up[up[u][i-1]][i-1];
    subMin[u] = u;
    for(int v : g[u]){
        dfs0(v, d+1);
        subMin[u] = min(subMin[u], subMin[v]);
    }
}
 
void dfs1(int u){
    vector<pair<int, int>> vs;
    for(int v : g[u]){
        vs.emplace_back(subMin[v], v);
    }
    sort(vs.begin(), vs.end());
    for(auto v : vs) {
        dfs1(v.second);
    }
    ind_in_seq[u] = seq.size();
    seq.push_back(u);
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q;
    for(int i = 0; i < n; ++i) cin >> up[i][0], --up[i][0];
    g.resize(n);
    for(int i = 0; i < n; ++i){
        if(up[i][0] == -1) root = i;
        else g[up[i][0]].push_back(i);
    }
    dfs0(root, 0);
    ind_in_seq.resize(n);
    dfs1(root);
  
    set<int> toAdd;
    for(int i=0; i<n; ++i) toAdd.emplace(i);
    int type, k;
    while(q--){
        cin >> type >> k;
        int ans = 0;
        if(type == 1){
            for(int i=0; i<k; ++i){
                ans = seq[*toAdd.begin()];
                toAdd.erase(toAdd.begin());
            }
            cout << ans+1 << '\n';
        }else{
            --k;
            int start = k;
            for(int i=17; i>=0; --i){
                while(up[k][i] != k && toAdd.find(ind_in_seq[up[k][i]])==toAdd.end()) k = up[k][i];
            }
            toAdd.insert(ind_in_seq[k]);
            cout << depth[start] - depth[k] << '\n';
        }
    }
}