#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	
	printf("enter number of elemnts: ");
	scanf("%d", &n);	

	int *arr = malloc(sizeof(int) * n);
	
	for(int i = 0; i < n; i ++)
		arr[i] = i;
	
	printf("our array:\n");
	for(int i = 0; i < n; i ++)
		printf("%d ", arr[i]);
	printf("\n");
	free(arr);
}
