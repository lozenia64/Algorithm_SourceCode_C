#include <iostream>
#include <algorithm> 
using namespace std;

int main(){
	int n, s;
	int arr[100010];
	scanf("%d %d", &n, &s);
	
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	
	int sum=arr[0], l=0, r=0, ans=987654321;
	
	while(l<=r && r<n){
		if(sum<s) sum+=arr[++r];
		else ans=min(ans,r-l+1), sum-=arr[l++];
	}
	printf("%d", ans>n ? 0 : ans);
}
