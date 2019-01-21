#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int tree[1000001];

long long calc(int height) {
    long long ans = 0;
    for(int i=1;i<=n;i++) {
        if(height<tree[i]) ans+=tree[i]-height;
    }
    return ans;
}

int main() {
    int mx=0;
    cin >> n >> m;

    for(int i=1;i<=n;i++) {
        cin >> tree[i];
        mx = max(tree[i],mx);
    }

    int l=0, r=mx, mid, ans=0;
    long long int tmp;

    while(l<r) {
        mid = (l+r)/2;
        tmp = calc(mid);
        if(tmp<m) r=mid;
        else ans = mid, l=mid+1;
    }

    cout << ans;
}
