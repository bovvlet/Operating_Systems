#include <stdio.h>
#include <stdlib.h>
#define N 10

FILE *my_file;

int get_min(int arr[]){
    int mi = 0;
    for(int j = 1; j < N; j ++)
        if(arr[mi] > arr[j])
            mi = j;

    return mi;
}

int exist(int arr[], int k){
    for(int j = 0; j < N; j ++)
        if(arr[j] == k)
            return 1;

    return 0;
}

int main() {

    my_file = fopen("/home/bovvlet/Desktop/Operating Systems/Week 9/Lab_09_input.txt", "r");

    if (!my_file) {
        perror("Could not open my_file.\n");
        return 0;
    }

    int i, free, cur;
    int miss_C, hit_C;
    int virt[N], age[N];
    miss_C = hit_C = 0;

    for(int i = 0; i < N; i ++)
        age[i] = 0;

    while( 1 == 1 )
    {
        fscanf(my_file, "%d", &cur);
        if( feof(my_file) )
            break;
        printf("%d\n\n", cur);
        if(exist(virt, cur) == 0){
            miss_C ++;
            free = get_min(age);
            virt[free] = cur;
            age[free] = 0;
        }
        else
            hit_C ++;

        for(int j = 0; j < N; j ++)
            age[i] = age[i] / 2;

        age[free] = age[free] * 2;
    }

    printf("Hit/miss = %d\n", (miss_C/hit_C));
    close(my_file);
    return 0;
}
