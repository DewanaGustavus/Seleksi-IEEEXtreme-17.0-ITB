#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    // int ans[n][n];
    range(i,0,n) {
        range(j,0,n) {
            // ans[i][j] = (i + j) % 2;
            cout << (i + j) % 2 << ((j != n-1) ? " " : "\n");
        }
    }

    return 0;
}