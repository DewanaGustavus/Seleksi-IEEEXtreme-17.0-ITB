#include <bits/stdc++.h>
using namespace std;

int ac() {
    exit(42);
}

int wa() {
    exit(43);
}


struct Prefsum2D{
    int n,m;
    vector<vector<int>> prefsum;
    Prefsum2D(vector<vector<int>> arr2d){
        n = arr2d.size();
        m = arr2d[0].size();
        prefsum = vector<vector<int>>(n+1, vector<int>(m+1));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                prefsum[i][j] = prefsum[i-1][j] + prefsum[i][j-1] - 
                prefsum[i-1][j-1] + arr2d[i-1][j-1];
    }

    int sumrange(int x1,int y1,int x2,int y2){
        return prefsum[x1][y1] - prefsum[x2][y1] - prefsum[x1][y2] + prefsum[x2][y2];
    }

};

int main(int argc, char *argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);

    int n, m;
    tc_in >> n >> m;
    vector<vector<int>> mat(n, vector<int>(n));
    string c;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> c;
            if(c == "0") {
                continue;
            }else if(c == "1") {
                mat[i][j] = 1;
            }else {
                cout << "Wrong output format at line " << i << " col " << j;
                return wa();
            }
        }
    }

    Prefsum2D prefsum(mat);
    int x1, y1, x2, y2;
    for(int i=0;i<m;i++) {
        tc_in >> x1 >> y1 >> x2 >> y2;
        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
        int sum1 = prefsum.sumrange(x1-1, y1-1, x2, y2);
        int sum0 = area - sum1;
        int dif = abs(sum1 - sum0);
        if(dif > 1) {
            cout << "Violate constraint " << i << "\n";
            cout << "val0 " << sum0 << " val1 " << sum1 << " dif " << dif;
            return wa();
        }
    }

    cout << "output correct\n";
    return ac();
}