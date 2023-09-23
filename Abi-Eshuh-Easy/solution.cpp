#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)        for(int i=s;i<e;i++)
#define ll long long

ll sigma(ll n){return n*(n+1)/2;}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int q;cin >> q;
while(q--) {
    ll x;cin >> x;
    int low = 0;
    int high = 1e9 + 5;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(sigma(mid) <= x) {
            ans = mid;
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    if(sigma(ans) < x)ans++;
    cout << ans << endl;
}
    
    
    return 0;
}








