#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

struct DSU{
    vector<int> link, size;
    int n, component;
    DSU(int length){
        n = length;
        component = length;
        link = vector<int>(n+1);
        size = vector<int>(n+1, 1);
        iota(link.begin(), link.end(), 0);
    }
    
    int find(int x){ // O(log(n))
        if(x != link[x])link[x] = find(link[x]);
        return link[x];
    }

    void unite(int a,int b){ // O(log(n))
        a=find(a); 
        b=find(b);
        if(a==b)return; 
        if(size[a]<size[b])swap(a,b); 
        size[a]+=size[b]; 
        link[b]=a; 
        component--;
    }
};

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int XMAX = 1e9;
    int N, M, X, A, B;
    vector<int> U, V, W;

    long long ans;
    void InputFormat() {
        LINE(N, M, X, A, B);
        LINES(U, V, W) % SIZE(M);
    }

    void OutputFormat() {
        LINE(ans);
    }
        
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= M <= NMAX);
        CONS(1 <= X <= XMAX);
        CONS(1 <= A <= N);
        CONS(1 <= B <= N);
        CONS(A != B);
        CONS(eachElementBetween(U, 1, NMAX));
        CONS(eachElementBetween(V, 1, NMAX));
        CONS(eachElementBetween(W, 1, XMAX));
        CONS(W.size() == M);
        CONS(U.size() == M);
        CONS(V.size() == M);
        CONS(isConnectedGraph(N,M,U,V));
        CONS(isCorrectEdges(N,M,U,V,false));
    }

private:
    bool eachElementBetween(vector<int> &v, int low, int high){
        for(int val : v){
            if(val < low || val > high)return false;
        }
        return true;
    }
    bool isConnectedGraph(int n, int m, vector<int> &u, vector<int> &v) {
        DSU dsu(n);
        for(int i=0;i<m;i++) {
            dsu.unite(u[i], v[i]);
        }
        return dsu.component == 1;
    }
    bool isCorrectEdges(int n, int m, vector<int> &u, vector<int> &v, bool directed) {
        set<pair<int,int>> edges;
        for(int i=0;i<m;i++) {
            if(u[i] == v[i])return false; // self loop
            // multi edge
            if(edges.count({u[i], v[i]}))return false;
            if(!directed && edges.count({v[i], u[i]}))return false;
            edges.insert({u[i], v[i]});
            if(!directed)edges.insert({v[i], u[i]});
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4 3 4 1 2",
            "4 3 247",
            "2 3 352",
            "1 4 300"
        });
        Output({
            "4"
        });
    }
    void BeforeTestCase() {
        U.clear();
        V.clear();
        W.clear();
    }
    void TestCases() {
        int n,m,x,a,b;
        for(int i=1;i<=10;i++) {
            n = rnd.nextInt(2, 10);
            int maxedges = (n/2) * (n-1);
            int maxrnd = min(NMAX, max(n-1, maxedges));
            m = rnd.nextInt(n-1, maxrnd);
            x = rnd.nextInt(1,n/2);
            a = rnd.nextInt(1,n-1);
            b = rnd.nextInt(a+1,n);
            CASE(N = n, M = m, X = x, A = a, B = b, randomGraph(n,m,U,V,W,60*1, 400*1));
        }
        for(int i=1;i<=10;i++) {
            n = rnd.nextInt(20, 100);
            int maxedges = (n/2) * (n-1);
            int maxrnd = min(NMAX, max(n-1, maxedges));
            m = rnd.nextInt(n-1, maxrnd);
            x = rnd.nextInt(10,n/2);
            a = rnd.nextInt(1,n-1);
            b = rnd.nextInt(a+1,n);
            CASE(N = n, M = m, X = x, A = a, B = b, randomGraph(n,m,U,V,W,60*1000, 400*1000));
        }
        for(int i=1;i<=10;i++) {
            n = rnd.nextInt(100, 1000);
            int maxedges = (n/2) * (n-1);
            int maxrnd = min(NMAX, max(n-1, maxedges));
            m = rnd.nextInt(n-1, maxrnd);
            x = rnd.nextInt(100,2*n);
            a = rnd.nextInt(1,n-1);
            b = rnd.nextInt(a+1,n);
            CASE(N = n, M = m, X = x, A = a, B = b, randomGraph(n,m,U,V,W,60*1e4, 400*1e4));
        }
        for(int i=1;i<=10;i++) {
            n = rnd.nextInt(1000, 1e4);
            int maxedges = (n/2) * (n-1);
            int maxrnd = min(NMAX, max(n-1, maxedges));
            m = rnd.nextInt(n-1, maxrnd);
            x = rnd.nextInt(10,n);
            a = rnd.nextInt(1,n-1);
            b = rnd.nextInt(a+1,n);
            CASE(N = n, M = m, X = x, A = a, B = b, randomGraph(n,m,U,V,W,60*1e6, 400*1e6));
        }
        for(int i=1;i<=10;i++) {
            n = rnd.nextInt(1e4, NMAX);
            int maxedges = (n/2) * (n-1);
            int maxrnd = min(NMAX, max(n-1, maxedges));
            m = rnd.nextInt(n-1, maxrnd);
            x = rnd.nextInt(1e3,n);
            a = rnd.nextInt(1,n-1);
            b = rnd.nextInt(a+1,n);
            CASE(N = n, M = m, X = x, A = a, B = b, randomGraph(n,m,U,V,W,60*1e6, XMAX));
        }
    }

private:
    void randomGraph(int n, int m, vector<int>& u, vector<int>& v, vector<int>& w, int low, int high) {
        DSU dsu(n);
        set<pair<int,int>> edges;
        int a, b, c;
        for(int i=0;i<n-1;i++) {
            c = rnd.nextInt(low, high);
            do {
                a = rnd.nextInt(1, n);
                b = rnd.nextInt(1, n);
            }while(a == b || dsu.find(a) == dsu.find(b));
            dsu.unite(a,b);
            u.push_back(a);
            v.push_back(b);
            w.push_back(c);
            edges.insert({a,b});
            edges.insert({b,a});
        }
        for(int i=n-1;i<m;i++) {
            c = rnd.nextInt(low, high);
            do {
                a = rnd.nextInt(1, n);
                b = rnd.nextInt(1, n);
            }while(a == b || edges.count({a,b}));
            u.push_back(a);
            v.push_back(b);
            w.push_back(c);
            edges.insert({a,b});
            edges.insert({b,a});
        }
	}
};