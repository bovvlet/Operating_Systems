#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
	return (a < b ? a : b);
}
int *my_realloc(int *arr, int n){
	if( n == 0 ){
		free(arr);
	}	
	else if( *arr == NULL ){
		arr = malloc(sizeof(int) * n);
	}
	else{
		int n_old = sizeof(arr) / sizeof(int);
		int *arr2 = malloc(sizeof(arr));
		for(int i = 0; i < n_old; i ++)
			arr2[i] = arr[i];
		free(arr);
		arr = malloc(sizeof(int) * n);
		for(int i = 0; i < min(n_old, n); i ++)
			arr[i] = arr2[i];
		free(arr2);
	}
}
int main(){
	int a[10];
	int *b = malloc(sizeof(int) * 10);

	my_realloc(b, 20);
	/// my_realloc(a, 5); if we try to pass array with fixed size our program crashes in passing it to the my_realloc() function
}
