#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;

    string S;
	int N;
    vector<int> vj, vi, vK;
    vector<char> vc;

    vector<int> ans;
	void InputFormat() {
        LINE(S);
        LINE(N);
        LINES(vj, vc, vi, vK) % SIZE(N);
	}

    void OutputFormat() {
    	LINES(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(4 <= S.size() <= NMAX);
        CONS(1 <= N <= NMAX);
        CONS(vj.size() == vc.size());
        CONS(vj.size() == vi.size());
        CONS(vj.size() == vK.size());
        CONS(eachElementBetween(vj, 1, S.size()));
        CONS(validLatinVectorChar(vc));
        CONS(validQueries(vi, vK));
    }
private:
    bool eachElementBetween(vector<int> &v, int low, int high){
        for(int val : v){
            if(val < low || val > high)return false;
        }
        return true;
    }
    bool validLatinVectorChar(vector<char> &v) {
        vector<int> asciival(v.size());
        for(int i=0;i<v.size();i++) {
            asciival[i] = v[i] - 'a';
        }
        return eachElementBetween(asciival, 0, 25);
    }
    bool validQueries(vector<int> &vi, vector<int> &vK) {
        if(!eachElementBetween(vi, 1, S.size() - 3)) {
            return false;
        }
        for(int i=0;i<vi.size();i++) {
            int upperBound = (S.size() - vi[i] + 1) / 4;
            if(vK[i] < 1 || vK[i] > upperBound)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "konpekokonpekokonpeko",
            "4",
            "14 p 11 1",
            "15 e 14 2",
            "16 k 14 2",
            "17 o 14 2"
        });
        Output({
        	"1",
        	"2",
        	"1",
            "0"
        });
    }

    void BeforeTestCase(){
        S.clear();
        vj.clear();
        vi.clear();
        vK.clear();
        vc.clear();
    }

    void TestCases() {
        string peko1 = "peko";
        string peko2 = "pekora";
        string peko3 = "usapeko";
        string peko4 = "abcdefghijklmnopqrstuvwxyz";
        string peko5 = "efghijklmnop";
        for(int i=0;i<10;i++)
            CASE(N = 10, 
                S = randomString(10, peko2), 
                randomUpdateQueries(S.size(), N, peko2, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
        for(int i=0;i<10;i++)
            CASE(N = 100, 
                S = randomString(100, peko3), 
                randomUpdateQueries(S.size(), N, peko3, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
        for(int i=0;i<10;i++)
            CASE(N = 1000, 
                S = randomString(1000, peko1), 
                randomUpdateQueries(S.size(), N, peko1, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
        for(int i=0;i<10;i++)
            CASE(N = 1e4, 
                S = randomString(1e4, peko2), 
                randomUpdateQueries(S.size(), N, peko2, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
        for(int i=0;i<10;i++)
            CASE(N = NMAX, 
                S = randomString(NMAX, peko3), 
                randomUpdateQueries(S.size(), N, peko3, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
        for(int i=0;i<10;i++)
            CASE(N = NMAX, 
                S = randomString(NMAX, peko4), 
                randomUpdateQueries(S.size(), N, peko4, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
        for(int i=0;i<10;i++)
            CASE(N = NMAX, 
                S = randomString(NMAX, peko5), 
                randomUpdateQueries(S.size(), N, peko5, vj, vc),
                randomQueries(S.size(), N, vi, vK);
                );
    }   

private:
    string randomString(int N, string charSet) {
        string s;
        for(int i=0;i<N;i++) {
            int idx = rnd.nextInt(0, charSet.size() - 1);
            s += charSet[idx];
        }
        return s;
    }
    char randomChar(string charSet) {
        int idx = rnd.nextInt(0, charSet.size() - 1);
        return charSet[idx];
    }
    void randomUpdateQueries(int SN, int N, string charSet, vector<int> &vj, vector<char> &vc) {
        for(int i=0;i<N;i++) {
            vj.push_back(rnd.nextInt(1, SN));
            vc.push_back(randomChar(charSet));
        }
    }
    void randomQueries(int SN, int N, vector<int> &vi, vector<int> &vK) {
        for(int i=0;i<N;i++) {
            int idx = rnd.nextInt(1, SN - 3);
            vi.push_back(idx);
            vK.push_back(rnd.nextInt(1, (SN - idx + 1) / 4));
        }
    }
};