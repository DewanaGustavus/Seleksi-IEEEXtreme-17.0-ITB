#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define range(i,s,e)        for(int i=s;i<e;i++)
#define all(vec)            (vec).begin(),(vec).end() 

ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}
ll binpow(ll a,ll b,ll m=INT64_MAX){ll r=1;a%=m;while(b){if(b&1)r=(r*a)%m;a=(a*a)%m;b>>=1;}return r;}
ll invmod(ll a,ll m){return gcd(a,m)==1?binpow(a,m-2,m):0;}

const ll MOD = 998244353;
const int maxn = 2e5+5;

ll evaluate(ll k, ll j, ll x) {
    ll remain = x - j;
    ll get = k * remain;
    return max(x, get - j) % MOD;
}

ll fac[maxn];
void init() {
    fac[0] = 1;
    range(i,1,maxn)fac[i] = (i * fac[i-1]) % MOD;
}

ll combin(ll n, ll m) {
    ll ret = fac[n];
    ret *= invmod(fac[m], MOD);
    ret %= MOD;
    ret *= invmod(fac[n-m], MOD);
    ret %= MOD;
    return ret;
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

    init();
    sort(all(bank), greater<ll>());
    ll total = 0;
    ll cnt = combin(n, m);
    range(i,0,n-m + 1) {
        total += combin(n - i - 1, m - 1) * bank[i];
        total %= MOD;
    }

    ll ans = total * invmod(cnt, MOD);
    ans %= MOD;
    cout << ans << endl;
    
    return 0;
}





