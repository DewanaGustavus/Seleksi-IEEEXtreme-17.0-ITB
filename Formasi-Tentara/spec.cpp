#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e3;
    const int MMAX = 1e3;
	int N, M;
    vector<int> x1, y1, x2, y2;

    vector<vector<int>> ans;
	void InputFormat() {
        LINE(N, M);
        LINES(x1, y1, x2, y2) % SIZE(M);
	}

    void OutputFormat1() {
        GRID(ans) % SIZE(N, N);
    }

    void StyleConfig() {
        CustomScorer();
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= M && M <= MMAX);
        CONS(validQueries(N, M, x1, y1, x2, y2));
    }

private:
    bool validQueries(int N, int M, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2) {
        if(x1.size() != M)return false;
        if(y1.size() != M)return false;
        if(x2.size() != M)return false;
        if(y2.size() != M)return false;
        for(int i=0;i<M;i++){
            if(x2[i] < x1[i] || y2[i] < y1[i])return false;
            if(x1[i] < 1 || x2[i] > N || y1[i] < 1 || y2[i] > N)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"5 3",
            "1 1 1 1",
            "1 2 4 3",
            "3 3 5 5"
        });
        Output({
            "0 0 0 0 0",
            "1 1 1 1 1",
            "0 0 0 0 1",
            "1 1 1 1 1",
            "0 0 0 0 0"
        });
    }

    void BeforeTestCase(){
        x1.clear();
        y1.clear();
        x2.clear();
        y2.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = 10, M = 3, randomQueries(M, N, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(5,50), M = 20, randomQueries(M, N, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(50,200), M = 50, randomQueries(M, N, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(200,500), M = 100, randomQueries(M, N, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = rnd.nextInt(500,NMAX), M = 300, randomQueries(M, N, x1, y1, x2, y2));
        for(int i=0;i<10;i++)CASE(N = NMAX, M = MMAX, randomQueries(M, N, x1, y1, x2, y2));
    }

private:
    void randomQueries(int M, int N, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2) {
        for(int i=0;i<M;i++){
            int xx1 = rnd.nextInt(1, N);
            int yy1 = rnd.nextInt(1, N);
            int xx2 = rnd.nextInt(xx1, N);
            int yy2 = rnd.nextInt(yy1, N);
            x1.push_back(xx1);
            y1.push_back(yy1);
            x2.push_back(xx2);
            y2.push_back(yy2);
        }
    }
};