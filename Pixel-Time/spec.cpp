#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int XMAX = 1e6;
    int N;
    vector<int> x1;
    vector<int> y1;
    vector<int> x2;
    vector<int> y2;

    int ans;
    void InputFormat() {
        LINE(N);
        LINES(x1, y1, x2, y2) % SIZE(N);
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
        CONS(array_cons(x1));
        CONS(array_cons(y1));
        CONS(array_cons(x2));
        CONS(array_cons(y2));
        CONS(array_size(x1, y1, x2, y2, N));
        CONS(no_same_grad(x1, y1, x2, y2));
    }

private:
    bool array_cons(vector<int> &val){
        if(val.size() != N)return false;
        for(int x : val){
            if(x > XMAX || x < -XMAX)return false;
        }
        return true;
    }
    bool array_size(vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, int N) {
        if(x1.size() != N)return false;
        if(y1.size() != N)return false;
        if(x2.size() != N)return false;
        if(y2.size() != N)return false;
        return true;
    }
    bool no_same_grad(vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2) {
        int N = x1.size();
        for(int i=0;i<N;i++) {
            long double angle1 = atan2l(x1[i], y1[i]);
            long double angle2 = atan2l(x2[i], y2[i]);
            if(angle1 < 0)angle1 += 2*M_PI;
            if(angle2 < 0)angle2 += 2*M_PI;
            if(angle1 == angle2)return false;
            if(angle1 > angle2)swap(angle1, angle2);
            if(angle1 + M_PI == angle2)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4",
            "-2 9 6 5",
            "0 5 10 3",
            "2 -8 10 -4",
            "-6 -6 0 -10"
        });
        Output({
        	"2"
        });
    }

    void BeforeTestCase(){
        x1.clear();
        y1.clear();
        x2.clear();
        y2.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 10, random_segments(N, 10, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = 50, random_segments(N, 100, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = 200, random_segments(N, 1000, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = 1000, random_segments(N, 1e4, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = 1e4, random_segments(N, 1e5, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = NMAX, random_segments(N, XMAX, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = NMAX, random_segments(N, 100, x1, y1, x2, y2));
    }

private:
    void random_segments(int N, int lim, vector<int> &vx1, vector<int> &vy1, vector<int> &vx2, vector<int> &vy2) {
        for(int i=0;i<N;i++) {
            int x1, y1;
            do {
                x1 = rnd.nextInt(-lim, lim);
                y1 = rnd.nextInt(-lim, lim);
            }while(x1 == 0 && y1 == 0);
            long double angle1 = atan2l(x1, y1);
            if(angle1 < 0)angle1 += 2*M_PI;
            int x2, y2;
            while(true) {                
                x2 = rnd.nextInt(-lim, lim);
                y2 = rnd.nextInt(-lim, lim);
                long double angle2 = atan2l(x2, y2);
                if(angle2 < 0)angle2 += 2*M_PI;
                if(angle1 == angle2)continue;
                long double minang = min(angle1, angle2);
                long double maxang = max(angle1, angle2);
                if(minang + M_PI == maxang)continue;
                break;
            }
            vx1.push_back(x1);
            vy1.push_back(y1);
            vx2.push_back(x2);
            vy2.push_back(y2);
        }
    }
};
