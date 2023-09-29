#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int XMAX = 1e9;
    int N, X;
    vector<int> val;

    int ans;
    void InputFormat() {
        LINE(N, X);
        LINE(val % SIZE(N));
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
        CONS(1 <= X <= XMAX);
        CONS(array_cons(val));
    }

private:
    bool array_cons(vector<int> &val){
        if(val.size() != N)return false;
        for(int x : val){
            if(x > XMAX || x <= 0)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 500",
            "10 20 10 20 10",
        });
        Output({
            "2"
        });
    }

    void SampleTestCase2() {
        Input({
            "5 100",
            "1 2 3 4 5",
        });
        Output({
            "-1"
        });
    }

    void BeforeTestCase(){
        val.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 10, X = rnd.nextInt(10,100), random_array(N, val, 5));
        for(int i=0;i<10;i++)CASE(N = 50, X = rnd.nextInt(100,1e4), random_array(N, val, 20));
        for(int i=0;i<10;i++)CASE(N = 200, X = rnd.nextInt(1e3,1e6), random_array(N, val, 50));
        for(int i=0;i<10;i++)CASE(N = 1000, X = rnd.nextInt(1e4,1e7), random_array(N, val, 200));
        for(int i=0;i<10;i++)CASE(N = 1e4, X = rnd.nextInt(1e4,1e8), random_array(N, val, 1e3));
        for(int i=0;i<10;i++)CASE(N = NMAX, X = rnd.nextInt(1e5,XMAX), random_array(N, val, XMAX));
        for(int i=0;i<10;i++)CASE(N = NMAX, X = rnd.nextInt(1e6,XMAX), random_array(N, val, 1e3));
    }

private:
    void random_array(int n, vector<int>& val, int lim){
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(1, lim));
        }
    }
};
