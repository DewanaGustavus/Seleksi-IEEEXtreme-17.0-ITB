#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)
#define ll long long

const int maxn = 2e5+5;
const int mod = 11;

int val[maxn];
vector<int> adj[maxn];
vector<vector<ll>> nodeval(maxn, vector<ll>(mod));

ll ans = 0;

void rooting(int node, int prev) {
    nodeval[node][val[node]] = 1;
    for(int nxt : adj[node]) {
        if(nxt == prev)continue;
        rooting(nxt, node);
        range(i,0,mod) {
            int nxti = (10 * i + val[node]) % mod;
            nodeval[node][nxti] += nodeval[nxt][i];
        }
    }
}

void dfsans(int node, int prev, vector<ll> parentval) {
    // re-rooting
    vector<ll> newparentval(mod);
    newparentval[val[node]] = 1;
    range(i,0,mod) {
        int nxti = (10 * i + val[node]) % mod;
        newparentval[nxti] += parentval[i];
        if(nxti == 0) {
            ans += newparentval[nxti];
        }
    }
    for(int nxt : adj[node]) {
        if(nxt == prev)continue;
        range(i,0,mod) {
            int nxti = (10 * i + val[node]) % mod;
            newparentval[nxti] += nodeval[nxt][i];
        }
    }

    for(int nxt : adj[node]) { // dfs
        if(nxt == prev)continue;
        vector<ll> nxtparentval(newparentval);
        range(i,0,mod) {
            int nxti = (10 * i + val[node]) % mod;
            if(nxti == 0) {
                ans += nodeval[nxt][i];
            }
            nxtparentval[nxti] -= nodeval[nxt][i];
        }
        dfsans(nxt, node, nxtparentval);
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

    rooting(0, -1);
    dfsans(0, -1, vector<ll>(mod));
    cout << ans << endl;

    return 0;
}








