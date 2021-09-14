#include<stdio.h>
#include<stdlib.h>
int main(){

printf("print 3 if you want to fork() 3 times, pring 5 for 5 times\n");
int choice;
scanf("%d", &choice);
if (choice == 3){
	fork();
	fork();
	fork();
	sleep(5);
}
else if(choice == 5){
	fork();
	fork();
	fork();
	fork();
	fork();
	sleep(5);
}
else{
	printf("wrong input");
}
return 0;
}
