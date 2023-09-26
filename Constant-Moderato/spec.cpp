#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

#define ll long long

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const ll XMAX = 1e9;
    int N, M, X;
    vector<ll> K, J;
    vector<ll> ans;
    
    void InputFormat() {
        LINE(N, M, J);
        LINES(K, J) % SIZE(N);
    }

    void OutputFormat1() {
        LINES(ans);
    }
        
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= M <= N);
        CONS(1 <= X <= XMAX);
        CONS(K.size() == N && J.size() == N);
        CONS(eachElementBetween(J, 1, XMAX));
        CONS(eachElementBetween(K, 1, XMAX));
    }
private:
    bool eachElementBetween(vector<ll> &v, ll low, ll high){
        for(ll val : v){
            if(val < low || val > high)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3 1 10",
            "2 7",
            "5 5",
            "16 8"
        });
        Output({
            "18"
        });
    }

    void SampleTestCase2() {
        Input({
            "3 2 10",
            "2 7",
            "5 5",
            "16 8"
        });
        Output({
            "665496258"
        });
    }

    void SampleTestCase3() {
        Input({
            "3 3 10",
            "2 7",
            "5 5",
            "16 8"
        });
        Output({
            "24"
        });
    }

    void BeforeTestCase(){
        J.clear();
        K.clear();
    }
    
    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 10, M = rnd.nextInt(1, N), X = rnd.nextInt(1,100), random_query(N, K, J, 1, 10));
        for(int i=0;i<10;i++)CASE(N = 100, M = rnd.nextInt(1, N), X = rnd.nextInt(100,1e3), random_query(N, K, J, 1, 100));
        for(int i=0;i<10;i++)CASE(N = 1e3, M = rnd.nextInt(1, N), X = rnd.nextInt(1e3,1e5), random_query(N, K, J, 1, 1e5));
        for(int i=0;i<10;i++)CASE(N = 1e4, M = rnd.nextInt(1, N), X = rnd.nextInt(1e5,XMAX), random_query(N, K, J, 1, XMAX));
        for(int i=0;i<10;i++)CASE(N = NMAX, M = rnd.nextInt(1, N), X = rnd.nextInt(1,XMAX), random_query(N, K, J, 1, XMAX));
    }
private:
    void random_query(int Q, vector<ll>& K, vector<ll>& J, int low, ll high) {
        for(int i=0;i<Q;i++) {
            K.push_back(rnd.nextLongLong(low, high));
            J.push_back(rnd.nextLongLong(low, high));
        }
    }
};
