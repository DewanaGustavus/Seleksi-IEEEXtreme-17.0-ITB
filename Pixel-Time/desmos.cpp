#include <bits/stdc++.h>
using namespace std;

int main() {

    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        int dy = y2 - y1;
        int dx = x2 - x1;
        int topb = y1 * dx - dy *x1;
        // a = dy / dx
        // b = y1 - a * x1
        // y = ax + b
        printf("y = %d/%d x + %d/%d {%d <= x <= %d}\n",
        dy,dx,topb,dx,x1,x2);
    }
    
    return 0;
}
