#include <bits/stdc++.h>
using namespace std;

namespace{
    vector<int> expected;
    vector<int> a, b;
    int n, m, asked, wmax;
    struct dsu{
        int n;
        vector<int> par;
        dsu(int n) : n(n), par(n){
            iota(par.begin(), par.end(), 0);
        }
        int root(int x){
            return x == par[x] ? x : (par[x] = root(par[x]));
        }
        bool merge(int x, int y){
            x = root(x); y = root(y);
            if(x == y) return 0;
            par[x] = y;
            return 1;
        }
    };
}


vector<int> findHiddenPermutation(int m);

vector<int> query(vector<int> W){
    asked++;
    if(asked > max(m + 5, 2 * m)){
        cout << "Too many queries" << endl;
        assert(0);
        return {};
    }
    if( ( (int) W.size() ) != m){
        cout << "Invalid size" << endl;
        assert(0);
        return {};
    }
    for(int w : W){
        if(w <= 0 || w >  1000000000){
            cout << "Weights must be in [0, 10^9] inclusive";
            assert(0);
            return {};
        }
        wmax = max(wmax, w);
    }

    dsu D(n);
    vector<int> perm(m);
    vector<int> weights(m);
    for(int i = 0; i < m; i++){
        perm[i] = i;
        weights[expected[i]] = W[i];
    }
    random_shuffle(perm.begin(), perm.end());
    sort(perm.begin(), perm.end(), [&](int i, int j){return weights[i] < weights[j];});
    vector<int> edges;
    for(int e : perm) if(D.merge(a[e], b[e])){
        //cout << "Join: " << a[e] << ' ' << b[e] << '\n';
        edges.push_back(e);
    }
    return edges;
}

int main(){
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++){
        asked = wmax = 0;
        cin >> n >> m;
        a.clear(); b.clear(); expected.clear();
        a.resize(m); b.resize(m); expected.resize(m);
        
        for(int i = 0; i < m; i++){
            cin >> expected[i];
        }

        for(int i = 0; i < m; i++){
            cin >> a[i] >> b[i];
        }
        vector<int> answer = findHiddenPermutation(m);

        if(answer != expected){
            cout << "Incorrect Output" << endl;
            return 0;
        }

        cout << "Correct!, Queries asked = " << asked << ", Maximum weight = " << wmax << endl;
    }
}