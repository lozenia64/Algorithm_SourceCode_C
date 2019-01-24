#include <iostream>
using namespace std;

int main() {
	int n, m;
	int arr[10010];
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		if (arr[i] == m) ans++;
		else {
			sum += arr[i];
			for (int j = i + 1; j < n; j++) {
				sum += arr[j];
				if (sum == m) {
					ans++;
					break;
				}
				else if (sum > m) break;	
			}
		}
	}
	
	cout << ans;
}
