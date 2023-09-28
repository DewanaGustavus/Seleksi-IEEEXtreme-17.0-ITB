#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

struct DSU{
    vector<int> link, size;
    int n;
    int component;
    DSU(int length){
        n = length;
        component = length;
        link = vector<int>(n+1);
        size = vector<int>(n+1, 1);
        for (int i = 1; i <= n; i++) link[i] = i;
    }
    
    int find(int x){ // O(log(n))
        int temp=x; 
        while(x!=link[x])x=link[x]; 
        link[temp]=x; 
        return x;
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
    const int AMAX = 9;
    int N;
    vector<int> value;
    vector<int> u;
    vector<int> v;

    long long ans;
    void InputFormat() {
        LINE(N);
        LINE(value % SIZE(N));
        LINES(u, v) % SIZE(N-1);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(value_cons(value));
        CONS(edges_cons(u, v));
    }

private:
    bool value_cons(vector<int> value){
        if(value.size() != N)return false;
        int pos = 1;
        for(int val : value){
            if(val > AMAX || val < 0)pos = 0;
        }
        return pos;
    }

    bool edges_cons(vector<int> u, vector<int> v){
        if(u.size() != N-1 && v.size() != u.size())return false;
        DSU comps(N);
        for(int i=0;i<N-1;i++){
            int a = u[i];
            int b = v[i];
            if(a < 1 || a > N || b < 1 || b > N)return 0;
            if(comps.find(a) == comps.find(b)){
                return 0;
            }
            comps.unite(a,b);
        }
        return 1;        
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void SampleTestCase1() {
        Input({
            "6",
            "0 3 3 3 5 2",
            "1 2",
            "2 3",
            "3 4",
            "2 5",
            "5 6"
        });
        Output({
            "13"
        });
    }

    void BeforeTestCase(){
        value.clear();
        u.clear();
        v.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 5, randomArray(N, value, 0, 9), random_tree(N, u, v));
        for(int i=0;i<10;i++)CASE(N = 10, randomArray(N, value, 0, 9), random_tree(N, u, v));
        for(int i=0;i<10;i++)CASE(N = 100, randomArray(N, value, 0, 9), random_tree(N, u, v));
        for(int i=0;i<10;i++)CASE(N = 1000, randomArray(N, value, 0, 9), random_tree(N, u, v));
        for(int i=0;i<10;i++)CASE(N = 1e4, randomArray(N, value, 0, 9), random_tree(N, u, v));
        for(int i=0;i<10;i++)CASE(N = NMAX, randomArray(N, value, 0, 9), random_tree(N, u, v));
    }

private:
    void randomArray(int N, vector<int> &val, int mn, int mx) {
        for (int i=0; i<N; i++){
            val.push_back(rnd.nextInt(mn, mx));
        }
    }

    void random_tree(int n, vector<int>& u, vector<int>& v){
        DSU container(n);
        for(int i=1;i<n;i++){
            int a,b;
            do{
                a = rnd.nextInt(1, n);
                b = rnd.nextInt(1, n);
            }while(container.find(a) == container.find(b));
            u.push_back(a);
            v.push_back(b);
            container.unite(a,b);
        }
    }
};