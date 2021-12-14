#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> //required
//#include <ext/pb_ds/tree_policy.hpp> //required

//using namespace __gnu_pbds; //required 
using namespace std;
//template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

// ordered_set <int> s;
// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

#define pb(x)            push_back(x)
#define mp(x,y)          make_pair(x,y)
#define all(x)           x.begin(), x.end()
#define print(vec,l,r)   for(int i = l; i <= r; i++) cout << vec[i] <<" "; cout << endl;
#define input(vec,N)     for(int i = 0; i < (N); i++) cin >> vec[i];
#define debug(x)         cerr << #x << " = " << (x) << endl;
#define leftmost_bit(x)  (63-__builtin_clzll(x))
#define rightmost_bit(x) __builtin_ctzll(x) // count trailing zeros
#define set_bits(x)      __builtin_popcountll(x) 
#define pow2(i)          (1LL << (i))
#define is_on(x, i)      ((x) & pow2(i)) // state of the ith bit in x
#define set_on(x, i)     ((x) | pow2(i)) // returns integer x with ith bit on
#define set_off(x, i)    ((x) & ~pow2(i)) // returns integer x with ith bit off
  
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// auto dist = uniform_int_distribution<int>(l, r);
// use int a = dist(rng) to get a random number between [l,r] inclusive

typedef long long int ll;
typedef long double ld;

const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5;
const ll INF = 1e18; // not too close to LLONG_MAX
const ld PI = acos((ld)-1);
const ld EPS = 1e-8;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}; // for every grid problem!!

// highly risky #defines
#define int ll // disable when you want to make code a bit faster
#define endl '\n' // disable when dealing with interactive problems

typedef vector<int> vi;
typedef pair<int, int> pii;

vector<vector<pii>> adj;
vector<vi> vec;
vi dist;
int N;

void bellman_ford(int src){
	dist[src] = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(pii p: adj[j]){
				int ne = p.first, w = p.second;

				if(dist[j] + w < dist[ne]){
					dist[ne] = w + dist[j];
				}
			}
		}
	}
}

void solve(){
	int M;
	cin >> N >> M;	

	adj.clear();
	vec.clear();
	adj.resize(N);
	dist.assign(N, INF);

	vi par(N, 1);
	for(int i = 1; i < N; i++) cin >> par[i];

	for(int i = 1; i < N; i++){
		par[i]--;
		adj[par[i]].push_back({i, 1});
		adj[i].push_back({par[i], 0});
	}
	for(int i = 0; i < M; i++){
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		u--;v--;
		vec.push_back({u, v, l, r});

		adj[u].push_back({v, r});
		adj[v].push_back({u, -l});
	}

	bellman_ford(0);
	// for(int i = 0; i < N; i++) cout << dist[i] << " ";
	// cout << endl;
	
	for(vi v: vec){		
		int t= dist[v[1]] -dist[v[0]];
		if(!(v[2] <= t && t <= v[3])){
			cout << -1 << endl;
			return;
		}
	}

	vi ans;
	
	for(int i = 1; i < N; i++){
		if(dist[i] == dist[par[i]]+1) ans.pb(i);
	}

	cout << ans.size() << endl;
	for(int i: ans) cout << i+1 << " ";
	cout << endl;

	
}


clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	//startTime = clock();
	// mt19937_64 rnd(time(NULL));
	
	int T = 1;
	cin >> T;

	while(T--){
		solve();
	}
	
	//cerr << getCurrentTime() << endl;
	return 0;
}
