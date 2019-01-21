#include <iostream>
#include <algorithm>
using namespace std;

int t, n, m, s[500500], cnt, arr[1001], brr[1001];
long long r;
int main() {
    scanf("%d %d", &t, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
            arr[i] += arr[i-1];
            for (int j=0; j<i; j++) s[cnt++] = arr[i]-arr[j];
        }
        sort(s, s+cnt);
        scanf("%d", &m);
        for (int i=1; i<=m; i++) {
                scanf("%d", brr[i]);
                brr[i] += brr[i-1];
                for (int j=0; j<i; j++)
                    r += upper_bound(s, s+cnt, t-brr[i]+brr[j])-lower_bound(s, s+cnt, t-brr[i]+brr[j]);
        }
        printf("%lld", r);
}
