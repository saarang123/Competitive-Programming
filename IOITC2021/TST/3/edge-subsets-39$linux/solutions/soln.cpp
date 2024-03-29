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

vi bellmanFord(const vector<vi> &edges){
    vi potential(n,INF);
    potential[0]=0;
    bool fl=true;
    for(int i=0;i<=n+1&&fl;++i){
        fl=false;
        for(const auto &e:edges){
            const lli u=e[0],v=e[1],w=e[2];
            if(potential[u]>=INF)
                continue;
            if(potential[v]<=potential[u]+w)
                continue;
            potential[v]=potential[u]+w;
            fl=true;
        }
        if(!fl)
            break;
    }

    if(fl)
        potential[0]=-1;

    return potential;
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
    vector<vi> bellman;
    for(int i=1;i<n;++i){
        lli par;
        cin>>par;
        par--;
        parent[i]=par;
        bellman.pb({i,par,0});
        bellman.pb({par,i,1});
    }

    map<ii,ii> constraints;
    for(int i=0;i<m;++i){
        lli u,v,l,r;
        cin>>u>>v>>l>>r;
        u--;v--;
        auto it=constraints.find({u,v});
        if(it!=constraints.end())
        {
            l=max(l,it->Y.X);
            r=min(r,it->Y.Y);
        }
        constraints[{u,v}]={l,r};
    }

    bool fl=true;
    for(auto x:constraints){
        const lli u=x.X.X,v=x.X.Y,l=x.Y.X,r=x.Y.Y;
        if(l>r)
            fl=false;
        bellman.pb({u,v,r});
        bellman.pb({v,u,-l});
    }

    if(!fl){
        cout<<"-1"<<endl;
        continue;
    }
    auto potential=bellmanFord(bellman);
    if(potential[0]<0){
        cout<<"-1"<<endl;
        continue;
    }
    vi chosen;
    for(int i=1;i<n;++i){
        if(potential[i]==1+potential[parent[i]]){
            chosen.pb(i);
        }
    }
    dbg(potential);
    fl=true;
    for(auto x:constraints){
        const lli u=x.X.X,v=x.X.Y,l=x.Y.X,r=x.Y.Y;
        if(potential[v]-potential[u]<l)
            fl=false;
        if(potential[v]-potential[u]>r)
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
