#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, nn;
int arr[100010][3], dp[2][3];

int main() {
	cin >> n;
	for(int i=0; i<n; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	
	bool flag=true;
	dp[0][0]=arr[0][0], dp[0][1]=arr[0][1], dp[0][2]=arr[0][2];
	for(int i=1; i<n; i++){
		if(flag){
			dp[1][0]=max(dp[0][0],dp[0][1])+arr[i][0];
			dp[1][1]=max({dp[0][0],dp[0][1],dp[0][2]})+arr[i][1];
			dp[1][2]=max(dp[0][1],dp[0][2])+arr[i][2];
			flag=false;	
		}
		else{
			dp[0][0]=max(dp[1][0],dp[1][1])+arr[i][0];
			dp[0][1]=max({dp[1][0],dp[1][1],dp[1][2]})+arr[i][1];
			dp[0][2]=max(dp[1][1],dp[1][2])+arr[i][2];
			flag=true;
		}
		
	}
	if(n%2==0) nn = 1;
	else nn=0;
	cout << max({dp[nn][0],dp[nn][1],dp[nn][2]}) << " ";

	memset(dp,0,sizeof(dp));
	flag=true;
	dp[0][0]=arr[0][0], dp[0][1]=arr[0][1], dp[0][2]=arr[0][2];
	for(int i=1; i<n; i++){
		if(flag){
			dp[1][0]=min(dp[0][0],dp[0][1])+arr[i][0];
			dp[1][1]=min({dp[0][0],dp[0][1],dp[0][2]})+arr[i][1];
			dp[1][2]=min(dp[0][1],dp[0][2])+arr[i][2];	
			flag=false;
		}
		else{
			dp[0][0]=min(dp[1][0],dp[1][1])+arr[i][0];
			dp[0][1]=min({dp[1][0],dp[1][1],dp[1][2]})+arr[i][1];
			dp[0][2]=min(dp[1][1],dp[1][2])+arr[i][2];
			flag=true;
		}
	}
	cout << min({dp[nn][0],dp[nn][1],dp[nn][2]});
}
