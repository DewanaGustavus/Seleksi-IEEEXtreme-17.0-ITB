#include <bits/stdc++.h>
using namespace std;

#define range(i,s,e)		for(int i=s;i<e;i++)

#define ld long double
#define pll pair<ld,ld>
#define pq  priority_queue

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    pq<pll, vector<pll>, greater<pll>> segments1; // {angle in, angle out} sorted by angle in
    pq<ld, vector<ld>, greater<ld>> segments2; // angle out, sorted by angle out
    int ans = 0;
    range(i,0,n) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // tan(tetha) = y/x
        ld sudut1 = atan2(y1,x1);
        ld sudut2 = atan2(y2,x2);
        if(sudut1 < 0)sudut1 += 2*M_PI;
        if(sudut2 < 0)sudut2 += 2*M_PI;
        if(sudut1 > sudut2)swap(sudut1, sudut2);

        ld diffsudut = sudut2 - sudut1;
        if(diffsudut == 0 || diffsudut == M_PI || diffsudut == 2*M_PI) {
            cout << "Testcase Salah";
        }
        if(diffsudut < M_PI) {
            segments1.push({sudut1, sudut2});
        }else {
            segments1.push({0, sudut1});
            segments1.push({sudut2, 2*M_PI});
        }
    }

    while(!segments1.empty()) {
        ld sudut = segments1.top().first;
        while(!segments1.empty() && segments1.top().first == sudut) {
            segments2.push(segments1.top().second);
            segments1.pop();
        }
        while(!segments2.empty() && segments2.top() < sudut) {
            segments2.pop();
        }
        ans = max(ans, (int)segments2.size());
        while(!segments2.empty() && segments2.top() == sudut) {
            segments2.pop();
        }
    }

    cout << ans << endl;
    
    
    return 0;
}

