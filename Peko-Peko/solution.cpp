#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)

struct segtree{
    // segment tree bottom up traversal
    // 0-indexing, left child is 2*i, right child is 2*i+1, parent is floor(i/2)
    // template for sum range
    int n;
    vector<int> segment;
    int init = 0; // initialize array value
    int operation(int a, int b){return a+b;} // segment tree operation
    segtree(int tn){
        n = log2(tn-1) + 1;
        n = (1<<n);
        segment = vector<int>(2*n, init);
    }
    void add(int idx, int val){
        idx += n;
        segment[idx] += val;
        for(idx/=2;idx>=1;idx/=2){
            segment[idx] = operation(segment[2*idx], segment[2*idx + 1]); 
        }
    }
    int sum(int l, int r) {
        l += n;
        r += n;
        int ans = init;
        while (l <= r) {
            if (l%2 == 1) ans = operation(ans, segment[l++]);
            if (r%2 == 0) ans = operation(ans, segment[r--]);
            l /= 2; r /= 2;
        }
        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    string peko = "peko";
    vector<segtree> pekost(4, (n/4) + 2);

    auto update = [&](int idx, char c, int decreaseval) {
        range(k,0,4) {
            if(idx - k < 0)break;
            int indexing = (idx - k) / 4;
            int pekoidx = (idx - k + 4) % 4;
            char pekochar = peko[pekoidx];
            pekost[k].add(indexing, (s[idx] != pekochar) ? decreaseval : 0);
            pekost[k].add(indexing, (c != pekochar) ? 1 : 0);
        }
        s[idx] = c;
    };

    range(i,0,n) {
        update(i, s[i], 0);
    }


    int idx, len;
    string t;
    char c;
    int q;cin >> q;
while(q--) {
    cin >> idx >> c;
    update(idx - 1, c, -1);
    cin >> idx >> len;
    int stidx = (idx-1) % 4;
    int stindexing = (idx-1) / 4;
    int ans = pekost[stidx].sum(stindexing, stindexing + len - 1);
    cout << ans << endl;
}
    
    
    return 0;
}


