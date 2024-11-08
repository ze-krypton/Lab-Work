#include <stdio.h>
int main(){
	int n,i;
	printf("Enter the range: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter array elements:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int sum=0,act_sum=0;
	sum = (n*(n+1))/2;
	for(i=0;i<n;i++){
		act_sum+=arr[i];
	}
	int mis = sum-act_sum;
	printf("The missing number is: %d",mis);
	return 0;
}
