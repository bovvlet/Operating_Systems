#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bubble_sort(int *a, int n){
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n-1; j ++)
			if(*(a + j) > *(a + j + 1))
				swap((a + j), (a + j + 1));
}
int main(){
	int n;
	int *a = malloc(sizeof(int) * n);
	printf("enter size of your array\n");
	scanf("%d", &n);
	for(int i = 0; i < n; i ++)
		scanf("%d", &(*(a + i)));
	bubble_sort(a, n);
	for(int i = 0; i < n; i ++)
		printf("%d ", *(a + i));
	printf("\n");
}

