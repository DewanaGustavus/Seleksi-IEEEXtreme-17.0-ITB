#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)        for(int i=s;i<e;i++)
#define range2(i,s,e)       for(int i=s;i>=e;i--)
#define ll                  long long
#define vi                  vector<int>
#define vvi                 vector<vi>

ll gcd(ll a, ll b){return (a==0?b:gcd(b%a,a));}
ll binpow(ll a,ll b,ll m=INT64_MAX){ll r=1;a%=m;while(b){if(b&1)r=(r*a)%m;a=(a*a)%m;b>>=1;}return r;}
ll invmod(ll a,ll m){return gcd(a,m)==1?binpow(a,m-2,m):0;}

const int MOD = 998244353;
const int maxn = 2e5+5;

void generatecombination(int n, int lim, vvi &combination, vi curarr = vector<int>(), int curn = 0) {
    if(curn == n) {
        combination.push_back(curarr);
    }else {
        range(i,0,lim) {
            curarr.push_back(i);
            generatecombination(n, lim, combination, curarr, curn + 1);
            curarr.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n, k;
    cin >> n >> k;
    ll a[n];
    range(i,0,n) cin >> a[i];
    vvi combin;
    generatecombination(n,k,combin);
    int ansval = 0;
    for(auto& v : combin) {
        int val = 0;
        int cntval[k] = {};
        range(i,0,k) {
            range(j,0,n) {
                if(v[j] == i) {
                    cntval[i] += a[j];
                }
            }
        }
        range(i,0,k) {
            val += binpow(cntval[i], 2, MOD);
            val %= MOD;
        }
        ansval += val;
        ansval %= MOD;
    }

    int combincnt = binpow(k,n,MOD);
    int ans = ansval * invmod(combincnt, MOD);
    ans %= MOD;
    cout << ans << endl;


    
    
    return 0;
}



