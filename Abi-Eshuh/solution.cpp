#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)        for(int i=s;i<e;i++)
#define ll long long

ll sigma(ll n){return n*(n+1)/2;}

const ll maxx = 2e18;
const ll maxans = 2e9 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int q;cin >> q;
while(q--) {
    ll x, k;cin >> x >> k;
    
    int low = 1;
    int high = (k == 1) ? maxans : min(maxans, (2 * maxx) / (k-1));
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        ll T2 = sigma(mid-1) + k*mid;
        if(T2 >= x) {
            ans = mid;
            high = mid - 1;
        }else {
            low = mid + 1;
        }
    }

    int T1 = ans * k;
    if(T1 > x)ans = -1;
    cout << ans << endl;
}
    
    
    return 0;
}








