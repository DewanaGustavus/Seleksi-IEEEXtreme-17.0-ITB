#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)    for(int i=s;i<e;i++)
#define ll              long long
#define vi              vector<ll>
#define pii             pair<int,ll>
#define vpii            vector<pii>
#define pq              priority_queue

const ll inf = 1e15;
const int maxn = 2e5+5;
int n;
vpii adj[maxn];

vi dijkstra(int node, ll speed){
    // Time Complexity : O(n + m log(m))
    vi dist(maxn, inf);
    bool visited[maxn] = {};
    dist[node]=0; 
    pq<pii> q; 
    q.push({0,node}); 

    while(!q.empty()){ 
        int curr = q.top().second;q.pop(); 
        if(visited[curr])continue; 
        visited[curr] = true;

        for(auto edge:adj[curr]){ 
            int next = edge.first;
            ll weight = (edge.second + speed - 1) / speed; // ceil div
            if(dist[curr] + weight < dist[next]){ 
                dist[next] = dist[curr] + weight;
                q.push({-dist[next],next}); 
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int m, start, end;
    ll X;
    cin >> n >> m >> X;
    cin >> start >> end;

    range(i,0,n) {
        int a,b,k;
        cin >> a >> b >> k;
        adj[a].emplace_back(b,k);
        adj[b].emplace_back(a,k);
    }

    ll low = 0;
    ll high = 1e9 + 5;
    ll ans = -1;
    while(low <= high) {
        ll kopi = (low + high) / 2;
        vi dist = dijkstra(start, 60ll * (kopi + 1));
        if(dist[end] <= X) {
            ans = kopi;
            high = kopi - 1;
        }else {
            low = kopi + 1;
        }
    }

    cout << ans << endl;
    
    
    return 0;
}

