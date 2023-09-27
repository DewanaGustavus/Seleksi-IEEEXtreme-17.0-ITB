#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
#define ll                  long long

ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}
ll binpow(ll a,ll b,ll m=INT64_MAX){ll r=1;a%=m;while(b){if(b&1)r=(r*a)%m;a=(a*a)%m;b>>=1;}return r;}
ll invmod(ll a,ll m){return gcd(a,m)==1?binpow(a,m-2,m):0;}

const int MOD = 998244353;
const int maxn = 2e5+5;
long long fac[maxn]; // precompute this

void init() {
    fac[0] = 1;
    for(int i=1;i<maxn;i++)fac[i] = (fac[i-1]*i) % MOD;
}

long long combinatoric_modulo(long long n, long long k){ // need inverse_modulo
    // Time Complexity : O(n) factorial precompute + O(log(m))
    if(n<k)return 0;
    if(k==0)return 1;
    long long ret = fac[n];
    ret = (ret * invmod(fac[k], MOD)) % MOD;
    ret = (ret * invmod(fac[n-k], MOD)) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    ll a[n];
    range(i,0,n) cin >> a[i];
    init();

    ll ansval = 0;
    int mask = 1 << n;
    int coffee = min(n, k) + 1;
    pair<ll,ll> dp[mask][coffee] = {}; // dp[mask][cnt coffee]
    dp[0][0] = {0,1};
    range(m1,0,mask) { // mask lama dan udah rating kopi
        range2(m2,mask-1,1) { // mask baru dan pengen nge rating 1 kopi yang sama
            if((m1 & m2) != 0)continue;
            
            ll m2val = 0;
            range(i,0,n) {
                if(m2 & (1 << i)) {
                    m2val += a[i];
                }
            }
            m2val = binpow(m2val, 2, MOD);

            range2(cnt,coffee-2,0) {
                dp[m1 | m2][cnt + 1].first += (m2val * dp[m1][cnt].second) + dp[m1][cnt].first;
                dp[m1 | m2][cnt + 1].first %= MOD;
                dp[m1 | m2][cnt + 1].second += dp[m1][cnt].second;
                dp[m1 | m2][cnt + 1].second %= MOD;
            }
        }
    }

    range(cnt,0,coffee) {
        ansval += dp[mask-1][cnt].first * combinatoric_modulo(k, cnt);
        ansval %= MOD;
    }

    ll combincnt = binpow(k,n,MOD);
    ll ans = ansval * invmod(combincnt, MOD);
    ans %= MOD;
    cout << ans << endl;
    
    
    return 0;
}





