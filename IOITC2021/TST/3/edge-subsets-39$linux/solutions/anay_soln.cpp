#include <iostream>
#include <vector>
#include <queue>

signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  
  while(t--) {
    int n, m;
    std::cin >> n >> m;
  
    std::vector<std::pair<int, std::pair<int, int> > > Adj[n];
    int p[n];

    for(int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      x--;
      p[i] = x;
      Adj[x].push_back({i, {0, 1}});
      Adj[i].push_back({x, {-1, 0}});
    }

    bool poss = true;

    for(int i = 0; i < m; i++) {
      int u, v, x, y;
      std::cin >> u >> v >> x >> y;
      u--; v--;
      if(y < x) {
        poss = false;
      }
      Adj[u].push_back({v, {x, y}});
      Adj[v].push_back({u, {-y, -x}});
    }

    if(!poss) {
      std::cout << -1 << std::endl;
      continue;
    }

    std::vector<int> l(n, 0), r(n, n), sz(n, n+1);

    r[0] = 0;
    sz[0] = 1;

    std::queue<std::pair<int, int> > q;

    q.push({0, 1});

    while(!q.empty()) {
      std::pair<int, int> u = q.front();

      if(u.second <= 0) {
        poss = false;
        break;
      }

      q.pop();

      if(u.second != sz[u.first])
        continue;

      for(auto j : Adj[u.first]) {
        int osz = sz[j.first];
        l[j.first] = std::max(l[j.first], l[u.first] + j.second.first);
        r[j.first] = std::min(r[j.first], r[u.first] + j.second.second);
        sz[j.first] = r[j.first]-l[j.first]+1;

        if(sz[j.first] < osz) {
          q.push({j.first, sz[j.first]});
        }
      }
    }

    if(!poss) {
      std::cout << -1 << std::endl;
      continue;
    }

    std::vector<int> ans;
    for(int j = 1; j < n; j++)
      if(l[j] > l[p[j]])
        ans.push_back(j+1);

    std::cout << ans.size() << std::endl;
    for(int j : ans)
      std::cout << j << " ";
    std::cout << std::endl;
  }

  return 0;
}

