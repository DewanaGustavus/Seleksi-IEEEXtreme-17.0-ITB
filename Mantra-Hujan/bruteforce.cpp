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
    vector<int> pick(n);
    ll val = 0;
    range(i,0,n) {
        cin >> a[i];
        val += a[i];
        pick[i] = i;
    }

    int INF = n + 5;
    int ans = (val >= x) ? 0 : INF;
    do {
        ll prev = 0;
        ll tmpval = val;
        range(i,0,n) {
            ll dif = abs(prev - a[pick[i]]);
            tmpval -= a[pick[i]];
            tmpval += dif * dif;
            if(tmpval >= x) {
                ans = min(ans, i + 1);
            }
            prev = a[pick[i]];
        }
    }while(next_permutation(pick.begin(), pick.end()));

    cout << (ans == INF ? -1 : ans) << endl;

    
    return 0;
}



