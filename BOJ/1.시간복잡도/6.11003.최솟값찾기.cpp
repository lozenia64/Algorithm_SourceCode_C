#include <iostream>
#include <deque>
using namespace std;

int main() {
	int n, l, m;
    deque<pair<int,int>> dq;
    scanf("%d%d", &n, &l);
    
    for(int i=0; i<n; i++) {
        scanf("%d",&m);
        while(!dq.empty() && dq.back().first>m) dq.pop_back();
        dq.push_back({m,i});
        if(i-l+1>=0 && dq.front().second<i-l+1) dq.pop_front();
        printf("%d ", dq.front().first);
    }
}
