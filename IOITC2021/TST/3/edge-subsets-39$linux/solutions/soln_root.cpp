/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

void relaxConstraints(vector<vi> &constraints){
    map<ii,ii> cons;
    for(auto &cur:constraints)
    {
        const lli u=cur[0],v=cur[1];
        lli l=cur[2],r=cur[3];
        auto it=cons.find({u,v});
        if(it!=cons.end())
        {
            l=max(l,it->Y.X);
            r=min(r,it->Y.Y);
        }
        cons[{u,v}]={l,r};
    }
    constraints.clear();
    for(auto x:cons)
        constraints.pb({x.X.X,x.X.Y,x.Y.X,x.Y.Y});
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>n>>m;
    vi parent(n);
    vector<vi> e(n);
    for(int i=1;i<n;++i){
        lli par;
        cin>>par;
        par--;
        parent[i]=par;
        e[par].pb(i);
    }

    vector<vi> constraints;
    for(int i=0;i<m;++i){
        lli u,v,l,r;
        cin>>u>>v>>l>>r;
        u--;v--;
        constraints.pb({u,v,l,r});
    }

    relaxConstraints(constraints);
    m=sz(constraints);
    bool fl=true;
    for(const auto &cur:constraints)
    {
        const lli u=cur[0],v=cur[1],l=cur[2],r=cur[3];
        if(l>r)
            fl=false;
    }

    if(!fl){
        cout<<"-1"<<endl;
        continue;
    }

    vi topo;
    function<void(int)> dfs = [&](int u){
        topo.pb(u);
        for(auto x:e[u])
            dfs(x);
    };
    dfs(0);

    vi chosen;
    auto bruteforce=[&]{
        vector<vi> subtree(n);
        for(int i=0;i<m;++i)
        {
            lli v=constraints[i][1];
            lli u=constraints[i][0];
            while(v!=u){
                subtree[v].pb(i);
                v=parent[v];
            }
        }
        for(auto cur:topo){
            bool fl=true;
            for(auto x:subtree[cur]){
                if(constraints[x][3]==0)
                    fl=false;
            }
            if(!fl)
                continue;
            chosen.pb(cur);
            for(auto x:subtree[cur]){
                constraints[x][3]--;
                constraints[x][2]--;
            }
        }
    };
    bruteforce();

    fl=true;
    for(const auto &cur:constraints)
    {
        if(cur[2]>0)
            fl=false;
    }
    if(!fl){
        cout<<"-1"<<endl;
        continue;
    }
    cout<<sz(chosen)<<endl;
    for(auto x:chosen)
        cout<<x+1<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}
