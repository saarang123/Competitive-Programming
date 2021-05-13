#include <bits/stdc++.h>
using namespace std;
#define maxn 1010
#define F first
#define S second
#define mp make_pair
#define pii pair<int,int>
#define ss second


void solve (int n, int &res);

namespace{

  int ed[maxn][maxn];

  int n, cnt;
  int out[maxn], in[maxn];

  int adj[maxn][maxn];
  int visited[maxn];
  int order[maxn];
  int tt = 0;

}

void dfs(int u) {
  visited[u] = 1;
  for(int i = 1;i <= n;i++) {
    if(adj[u][i] && !visited[i]) {
      dfs(i);
    }
  }
  order[++tt] = u;
}



int main(){
  cin>>n;
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++) {
      cin>>ed[i][j];
      adj[i][j] = ed[i][j];
    }
  }
  for (int i=1; i<=n; i++){
    for (int j=1;  j<=n; j++){
      if (!ed[i][j] and !ed[j][i]) {
        if (i==j) continue;
        cout<<"bad"<<endl;
        assert(0);
      }
    }
  }
  for (int i=1; i<=n; i++){
    for (int j=1; j<=n; j++){
      if (ed[i][j]){
        out[i]++;
        in[j]++;
      }
    }
  }

  int res;

  for(int i = 1;i <= n;i++) {
    if(!visited[i])
      dfs(i);
  }
  assert(tt == n);
  reverse(order+1,order+1+n);
  for(int i = 1;i <= n;i++)
    visited[i] = 0;
  for(int i = 1;i <= n;i++) {
    for(int j = 1;j < i;j++) {
      swap(adj[i][j],adj[j][i]);
    }
  }
  res = 1;
  dfs(order[1]);
  for(int i = 1;i <= n;i++) {
    if(!visited[i]) {
      res = 0;
    }
  }

  
  int fin;
  solve(n, fin);
  cout<<fin<<"\n";
  if (fin==res){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }


}


vector < pair <int, int> > init (){
  vector < pair <int, int> > v;
  for (int i=0; i<n; i++) v.push_back(make_pair(in[i+1], out[i+1]));
  return v;
}
  


bool query (int i, int j){
  if (i==j or i<=0 or i>n or j<=0 or j>n){
    fprintf(stderr, "invalid \n");
    assert(0);
    return 0;
  }
  if (ed[i][j]==1) cnt++;
  if (cnt>n){

    fprintf(stderr, "limit exceeded \n");
    assert(0);
    return 0;
  }
  return (ed[i][j]==1);
}
