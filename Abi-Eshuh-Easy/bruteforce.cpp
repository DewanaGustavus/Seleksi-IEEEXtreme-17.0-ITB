#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    const int INF = 1e9;
    const int maxn = 505; 
    int dp[maxn][maxn]; // dp[i][j] = minimum cost to remove j if we currently at i power
    range(i,0,maxn)range(j,0,maxn)dp[i][j] = INF;
    range(i,0,maxn)dp[i][0] = 0;
    range2(i,maxn-2,0)range(j,0,maxn) {
        if((j-i) >= 0)dp[i][j] = min(dp[i][j-i], dp[i+1][j-i]) + 1;
    }

    int q;cin>>q;
while(q--){
    int x;cin >> x;
    cout << dp[1][x] << endl;
}
    
    
    return 0;
}








