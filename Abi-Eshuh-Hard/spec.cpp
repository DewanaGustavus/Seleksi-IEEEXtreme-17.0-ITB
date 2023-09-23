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
        for(int i=0;i<10;i++)CASE(Q = 10, random_query(Q, X, K, 100));
        for(int i=0;i<10;i++)CASE(Q = 100, random_query(Q, X, K, QMAX));
        for(int i=0;i<10;i++)CASE(Q = 1000, random_query(Q, X, K, 1e9));
        for(int i=0;i<10;i++)CASE(Q = 1e4, random_query(Q, X, K, 1e12));
        for(int i=0;i<10;i++)CASE(Q = QMAX, random_query(Q, X, K, XMAX));
    }
private:
    void random_query(int Q, vector<ll> &X, vector<ll> &K, ll high) {
        for(int i=0;i<Q;i++) {
            ll xval = rnd.nextLongLong(1, high);
            X.push_back(xval);
            K.push_back(rnd.nextLongLong(1, xval));
        }
    }
};
