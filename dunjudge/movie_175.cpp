#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m; cin >> n >> m;
  int A[n + 1];
  map < int, int > mp;
  for(int i = 1; i <= n; i++){
    cin >> A[i];
    mp[A[i]] = i;
  }
  vector < int > B;
  for(int i = 1; i <= m; i++){
    int x; cin >> x;
    if(mp.count(x)){
      B.push_back(mp[x]);
    }
  }
  set < int > st;
  for(auto x : B){
    st.insert(x);
    auto it = st.lower_bound(x);
    it++;
    if(st.end() != it){
      st.erase(it);
    }
  }
  cout << (int)st.size();
  return 0;
}
