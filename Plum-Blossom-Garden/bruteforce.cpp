#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)
#define ll long long

const int maxn = 2e5+5;

int val[maxn];
vector<int> adj[maxn];
ll ans = 0;

void dfs(int node, int prev, int value) {
    if(value == 0)ans++;
    for(int nxt : adj[node]) {
        if(nxt == prev)continue;
        int nxtval = ((10 * value) + val[nxt]) % 11;
        dfs(nxt, node, nxtval);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    range(i,0,n)cin >> val[i];
    range(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    range(i,0,n) {
        dfs(i, -1, val[i]);
    }

    cout << ans << endl;

    return 0;
}








