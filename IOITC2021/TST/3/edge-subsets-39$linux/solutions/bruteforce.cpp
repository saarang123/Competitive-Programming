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

    vi ord;
    function<void(int)> dfs = [&](int u){
        ord.pb(u);
        for(auto x:e[u])
            dfs(x);
    };
    dfs(0);

    vector<vi> constraints;
    for(int i=0;i<m;++i){
        lli u,v,l,r;
        cin>>u>>v>>l>>r;
        u--;v--;
        constraints.pb({u,v,l,r});
    }

    lli ans=-1;
    for(lli msk=0;2*msk<(1LL<<n);++msk){
        vi potential(n);
        for(auto u:ord)
        {
            if(u==0)
                continue;
            const lli i=u-1,p=parent[u];
            potential[u]=potential[p];
            if(msk&(1LL<<i)){
                potential[u]++;
            }
        }

        bool fl=true;
        for(const auto &cur:constraints){
            const lli u=cur[0],v=cur[1],l=cur[2],r=cur[3];
            if(potential[v]-potential[u]<l)
                fl=false;
            if(potential[v]-potential[u]>r)
                fl=false;
        }

        if(fl){
            ans=msk*2;
            break;
        }
    }

    if(ans==-1){
        cout<<ans<<endl;
        continue;
    }

    vi chosen;
    for(int i=0;i<n;++i){
        if(ans&(1LL<<i))
            chosen.pb(i);
    }
    cout<<sz(chosen)<<endl;
    for(auto x:chosen)
        cout<<x+1<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}
