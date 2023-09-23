#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s; cin >> s;    
    int idx, len;
    string t;
    char c;
    string peko = "peko";
 
    int q;cin >> q;
while(q--) {
    cin >> idx >> c;
    s[idx - 1] = c;
    cin >> idx >> len;
    int change = 0;
    range(i, 0, len * 4) {
        char pc = peko[i % 4];
        if(s[idx + i - 1] != pc)change++;
    }
    cout << change << endl;
}
    
    
    return 0;
}








