#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

#define ll long long

class ProblemSpec : public BaseProblemSpec {
protected:
    const int QMAX = 1e5;
    const ll XMAX = 1e18;
    int Q;
    vector<ll> X, K;
    vector<ll> ans;
    
    void InputFormat() {
        LINE(Q);
        LINES(X, K) % SIZE(Q);
    }

    void OutputFormat1() {
        LINES(ans);
    }
        
    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= Q <= QMAX);
        CONS(X.size() == Q && K.size() == Q);
        CONS(eachElementBetween(X, 1, XMAX));
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
    void SampleTestCase() {
        Input({
            "2",
            "10 6",
            "100 5"
        });
        Output({
            "-1",
            "11"
        });
    }

    void BeforeTestCase(){
        X.clear();
        K.clear();
    }
    
    void TestCases() {
        for(int i=0;i<10;i++)CASE(Q = 10, random_query(Q, X, K, 1, 100));
        for(int i=0;i<10;i++)CASE(Q = QMAX, random_query(Q, X, K, 1, QMAX));
        for(int i=0;i<10;i++)CASE(Q = QMAX, random_query(Q, X, K, 1, 1e9));
        for(int i=0;i<10;i++)CASE(Q = QMAX, random_query(Q, X, K, 1, 1e12));
        for(int i=0;i<10;i++)CASE(Q = QMAX, random_query(Q, X, K, 1, XMAX));
    }
private:
    void random_query(int Q, vector<ll> X, vector<ll> K, int low, ll high) {
        for(int i=0;i<Q;i++) {
            X.push_back(rnd.nextLongLong(low, high));
            K.push_back(rnd.nextLongLong(low, high));
        }
    }
};
