#include <bits/stdc++.h>
using namespace std;
 
#define range(i,s,e)		for(int i=s;i<e;i++)
#define ll                  long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int n, x; 
    cin >> n >> x;
    vector<int> a(n);
    ll val = 0;
    range(i,0,n) {
        cin >> a[i];
        val += a[i];
    }

    sort(a.begin(), a.end());

    int INF = n + 5;
    int ans = (val >= x) ? 0 : INF;
    vector<int> order;
    int j=0;
    range(k,0,n) {
        j = n - j;
        if(k % 2)j++;
        order.push_back(j);
    }

    ll prev = 0;
    range(i,0,n) {
        ll dif1 = abs(prev - a[order[i] - 1]);
        val -= a[order[i]-1];
        val += dif1 * dif1;
        if(val >= x) {
            ans = min(ans, i + 1);
        }
        prev = a[order[i]-1];
    }

    cout << (ans == INF ? -1 : ans) << endl;

    
    return 0;
}





