#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define range(i,s,e)        for(int i=s;i<e;i++)
#define all(vec)            (vec).begin(),(vec).end() 

ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}
ll binpow(ll a,ll b,ll m=INT64_MAX){ll r=1;a%=m;while(b){if(b&1)r=(r*a)%m;a=(a*a)%m;b>>=1;}return r;}
ll invmod(ll a,ll m){return gcd(a,m)==1?binpow(a,m-2,m):0;}

const ll MOD = 998244353;

ll evaluate(ll k, ll j, ll x) {
    ll remain = x - j;
    ll get = k * remain;
    return max(x, get - j);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll n,m,x;
    cin >> n >> m >> x;
    vector<ll> bank(n);
    range(i,0,n) {
        ll k, j;
        cin >> k >> j;
        bank[i] = evaluate(k, j, x);
    }

    vector<int> vec(n);
    range(i,0,m)vec[i] = 1;
    sort(all(vec));
    ll total = 0;
    ll cnt = 0;
    do{
        ll maxi = x;
        range(i,0,n) {
            if(vec[i]) {
                maxi = max(maxi, bank[i]);
            }
        }
        total += maxi;
        total %= MOD;
        cnt++;
    }while(next_permutation(all(vec)));

    ll ans = total * invmod(cnt, MOD);
    ans %= MOD;
    cout << ans << endl;
    
    return 0;
}





