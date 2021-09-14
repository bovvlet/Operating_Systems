#include<stdio.h>
#include<stdlib.h>

int n;
int main(){
printf("Enter number of iterations: ");
scanf("%d", &n);
 int pid = fork();
for(int i = 0; i < n; i ++){
    if(pid > 0){
        printf("hello from parent [%d - %d]\n", pid, i);
    }
    else if(pid == 0){
        printf("hello from child \n");
    }
}
    return 0;
}
