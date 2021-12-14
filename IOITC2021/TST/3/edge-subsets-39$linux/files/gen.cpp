#include "jngen.h"
#ifdef ARYANC403
    #include <header.h>
#else
    #include <bits/stdc++.h>
    #define dbg(args...) 42;
#endif

using namespace std;

using lli = long long int;
using vi = vector<lli>;
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())

lli randNext(lli l,lli r){
    return rnd.next(l,r);
}

struct Test {
    vector<int> parents;
    vector<vector<int>> conditions;
};

vector <Test> tests;

void printTestsStdout() {
    fprintf(stdout, "%d\n",(int)tests.size());
    for (int t = 0; t < (int)tests.size(); t++) {
        Test& test = tests[t];
        const int n=sz(test.parents)+1;
        const int m=sz(test.conditions);
        fprintf(stdout, "%d %d\n", n, m);
        for (int i = 0; i < (int)test.parents.size(); i++)
            fprintf(stdout, "%d%c", test.parents[i], i + 1 == (int)test.parents.size() ? '\n' : ' ');
        for(const auto &con:test.conditions)
            fprintf(stdout, "%d %d %d %d\n", con[0],con[1],con[2],con[3]);
    }
}

vector<Tree> getFullSubtaskTree(const int T,const int NL,const int NR){
    const int Elong = 10000;
    vector<Tree> trees;
    for(int tc=0;sz(trees)<T;++tc){
        const int n=randNext(NL,NR);
        trees.push_back(Tree::random(n));
        trees.push_back(Tree::randomPrim(n,randNext(-Elong,Elong)));
        trees.push_back(Tree::randomPrim(n,randNext(-Elong,Elong)));
        trees.push_back(Tree::randomPrim(n,randNext(-Elong,Elong)));
        trees.push_back(Tree::randomKruskal(n));
        trees.push_back(Tree::bamboo(n));
        trees.push_back(Tree::star(n));
        trees.push_back(Tree::caterpillar(n,randNext(1,n)));
        trees.push_back(Tree::caterpillar(n,randNext(1,n)));
        trees.push_back(Tree::binary(n));
        trees.push_back(Tree::kary(n,2+randNext(0,(int)sqrt(n))));
        trees.push_back(Tree::kary(n,2+randNext(0,(int)sqrt(n))));
    }
    return trees;
}

vector<int> randomshuffleParents(const vector<int> par){
    const int n = sz(par);
    auto perm=Array::id(n).shuffled();
    for(int i=1;i<n;++i){
        if(perm[i]==0)
            swap(perm[i],perm[0]);
    }
    vector<int> spar(n);
    for(int i=0;i<n;++i){
        spar[perm[i]]=perm[par[i]];
    }
    return spar;
}

template <typename T>
void randomShuffleVector(vector<T> &a){
    const int n=sz(a);
    for(int i=1;i<n;++i)
        swap(a[i],a[randNext(0,i-1)]);
    for(int i=1;i<n;++i)
        swap(a[i],a[randNext(0,i-1)]);
}

vector<int> getHeights(const vector<int> &par,const vector<int> &weights){
    const int n=sz(par);
    vector<int> heights(n,n+100);
    heights[0]=0;
    lli cnt=n-1;
    while(cnt){
        for(int i=0;i<n;++i){
            if(heights[i]>n&&heights[par[i]]<=n)
            {
                heights[i]=heights[par[i]]+weights[i];
                cnt--;
            }
        }
    }
    return heights;
}

void randomTest(Tree t,int m){
    Test test;
    auto par = t.parents(0);
    par[0]=0;
    par=randomshuffleParents(par);
    const int n=sz(par);
    for(int i=1;i<n;++i)
        test.parents.push_back(par[i]+1);
    vector<int> weights(n,1);
    weights[0]=0;
    for(auto &x:weights)
        x=randNext(0,1);
    const auto weightsPrefixSums=getHeights(par,weights);
    const bool rootonly = getOpt("rootonly", false);
    const bool liIsNonZero = getOpt("li", true);
    const bool fl=(randNext(0,10)==0);

    auto jump=[&](int u,int h){
        while(h>0&&u!=0){
            u=par[u];
            h--;
        }
        return u;
    };

    auto randomCondition=[&](){
        const int v=randNext(0,n-1);
        const int h=(rootonly?n:randNext(0,n-1));
        const int u=jump(v,h);
        int sum=weightsPrefixSums[v]-weightsPrefixSums[u];
        if(fl)
            sum=randNext(0,n-1);
        const int l=(liIsNonZero?randNext(0,sum):0);
        const int r=randNext(sum,n-1);
        return vector<int>({u+1,v+1,l,r});
    };

    auto &conditions=test.conditions;
    for(int i=0;i<m;++i){
        conditions.push_back(randomCondition());
    }
    tests.push_back(test);
}

void rootOnlyCycles(Tree t){
    Test test;
    auto par = t.parents(0);
    par[0]=0;
    par=randomshuffleParents(par);
    const int n=sz(par);
    for(int i=1;i<n;++i)
        test.parents.push_back(par[i]+1);
    vector<int> weights(n,1);
    weights[0]=0;
    const auto heights=getHeights(par,weights);
    for(auto &x:weights)
        x=randNext(0,1);
    const auto weightsPrefixSums=getHeights(par,weights);
    const bool rootonly = getOpt("rootonly", false);
    const bool liIsNonZero = getOpt("li", true);

    auto jump=[&](int u,int h){
        while(h>0&&u!=0){
            u=par[u];
            h--;
        }
        return u;
    };

    auto &conditions=test.conditions;
    for(int v=1;v<n;++v){
        int l=weightsPrefixSums[0],r=weightsPrefixSums[v];
        if(randNext(0,1)){
            l=min(heights[v]+1,n-1);
            r=min(heights[v]+2,n-1);
        }
        conditions.push_back({1,v+1,l,r});
    }
    randomShuffleVector(conditions);
    tests.push_back(test);
}

void negativeCyclesTest(Tree t){
    Test test;
    auto par = t.parents(0);
    par[0]=0;
    par=randomshuffleParents(par);
    const int n=sz(par);
    for(int i=1;i<n;++i)
        test.parents.push_back(par[i]+1);
    vector<int> weights(n,1);
    weights[0]=0;
    const auto heights=getHeights(par,weights);
    for(auto &x:weights)
        x=randNext(0,1);
    const auto weightsPrefixSums=getHeights(par,weights);
    const bool rootonly = getOpt("rootonly", false);
    const bool liIsNonZero = getOpt("li", true);

    auto jump=[&](int u,int h){
        while(h>0&&u!=0){
            u=par[u];
            h--;
        }
        return u;
    };

    auto randomCondition=[&](){
        const int v=randNext(0,n-1);
        const int h=(rootonly?n:randNext(0,n-1));
        const int u=jump(v,h);
        const int sum=weightsPrefixSums[v]-weightsPrefixSums[u];
        const int l=(liIsNonZero?sum:0);
        const int r=randNext(sum,n-1);
        return vector<int>({u+1,v+1,l,r});
    };

    auto getRandomNegativeCycle=[&](){
        const int v=randNext(0,n-1);
        const int h=(rootonly?n:randNext(0,n-1));
        const int u=jump(v,h);
        vector<vector<int>> cycle;
        int down=v;
        while(down!=u){
            const int jp=randNext(0,heights[down]-heights[u]);
            const int anc=jump(down,jp);
            const int l=randNext(weightsPrefixSums[anc],weightsPrefixSums[down]);
            const int r=randNext(weightsPrefixSums[anc],weightsPrefixSums[down]);
            cycle.push_back({anc+1,down+1,min(l,r),max(l,r)});
            down=anc;
        }
        cycle.push_back({u+1,v+1,weightsPrefixSums[u],weightsPrefixSums[v]});
        return cycle;
    };

    auto &conditions=test.conditions;
    conditions=getRandomNegativeCycle();
    const int m=n;
    if(randNext(0,1)){
        while(sz(conditions)<m){
            if(randNext(0,1)){
                conditions.push_back(randomCondition());
            } else {
                auto cycle=getRandomNegativeCycle();
                conditions.insert(conditions.end(),all(cycle));
            }
        }
        conditions.resize(m);
    }
    randomShuffleVector(conditions);
    tests.push_back(test);
}

int main(int argc, char *argv[]) {
    registerGen(argc, argv);
    parseArgs(argc, argv);
    /***
        ./T NL NR ML MR seed
        ./T NL NR ML MR seed -rootonly=1 -stress=1 -li=0 -negativecycles=80
        T is no of tests.
        n is in range [NL,NR]
        m is in range [ML,MR]
        Optional parameters -
            -stress should be 1 only for stress testing.
            -rootonly is true for subtask with ui=root only.
            -li should be 0 for subtask with li=0.
            -negativecycles to call negativeCyclesTest() with p/100 probability
    ***/
    const int T = getOpt(0);
    const int NL = getOpt(1);
    const int NR = getOpt(2);
    const int ML = getOpt(3);
    const int MR = getOpt(4);
    const int seed = getOpt(5);

    const bool stress = getOpt("stress", false);
    if(!stress)
        rnd.seed(seed);

    const bool rootonly = getOpt("rootonly", false);
    const bool liIsNonZero = getOpt("li", true);
    const int negativeCyclesProb = getOpt("negativecycles", 20);
    dbg(negativeCyclesProb);
    vector<Tree> trees;
    trees=getFullSubtaskTree(T,NL,NR);
    randomShuffleVector(trees);
    for(int tc=0;tc<T;++tc){
        const int m=randNext(ML,MR);
        if(liIsNonZero&&randNext(0,100)<=negativeCyclesProb)
            if(rootonly)
                rootOnlyCycles(trees[tc]);
            else
                negativeCyclesTest(trees[tc]);
        else
            randomTest(trees[tc],m);
    }
    printTestsStdout();
    return 0;
}
