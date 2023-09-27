#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 14;
    const int KMAX = 1e8;
    const int AMAX = 1e9;
    int N, K;
    vector<int> val;

    int ans;
    void InputFormat() {
        LINE(N, K);
        LINE(val % SIZE(N));
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= K <= KMAX);
        CONS(array_cons(val));
    }

private:
    bool array_cons(vector<int> &val){
        if(val.size() != N)return false;
        for(int x : val){
            if(x > AMAX || x <= 0)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 1",
            "1 2 3 4 5"
        });
        Output({
        	"225"
        });
    }

    void SampleTestCase2() {
        Input({
            "3 4",
            "1 2 3"
        });
        Output({
        	"499122196"
        });
    }

    void BeforeTestCase(){
        val.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 2, K = rnd.nextInt(1,10), random_array(N, val, 10));
        for(int i=0;i<10;i++)CASE(N = 5, K = rnd.nextInt(1,100), random_array(N, val, 1e3));
        for(int i=0;i<10;i++)CASE(N = 7, K = rnd.nextInt(1,1e4), random_array(N, val, 1e6));
        for(int i=0;i<10;i++)CASE(N = 10, K = rnd.nextInt(1,1e6), random_array(N, val, AMAX));
        for(int i=0;i<10;i++)CASE(N = NMAX, K = rnd.nextInt(1,KMAX), random_array(N, val, AMAX));
    }

private:
    void random_array(int n, vector<int>& val, int nmax){
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(1, nmax));
        }
    }
};
