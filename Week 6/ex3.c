#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task {
    int arrive_T;
    int burst_T;
    int proc_ID;
    bool Finished;
    int left_T;
}Task;

Task* new_task(int arrive_T, int burst_T, int id) {
    Task* task = malloc(sizeof (Task*));
    task->arrive_T = arrive_T;
    task->burst_T = burst_T;
    task->proc_ID = id;
    task->Finished = false;
    return task;
}

double calc_average(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total = total + arr[i];
    return total / (n * 1.0);
}

void T_sort(Task* arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i]->arrive_T > arr[j]->arrive_T) {
                Task box = *arr[i];
                *arr[i] = *arr[j];
                *arr[j] = box;
            }
        }
    }
}

int main() {
    int n, cur_T = 0, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Task* arr[n];
    int ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        int arrive_T, burst_T;
        printf("Enter arrival time of process #%d: ", (i + 1));

        scanf("%d", &arrive_T);
        printf("Enter burst time of process #%d: ", (i + 1));

        scanf("%d", &burst_T);
        arr[i] = new_task(arrive_T, burst_T, (i + 1));
    }
    T_sort(arr, n);

    printf("Enter a quantum: ");
    scanf("%d", &quantum);

    T_sort(arr, n);

    int HaveToDo = n;
    while (HaveToDo) {
        for (int i = 0; i < n; i++) {
            if (!arr[i]->Finished) {
                if (arr[i]->left_T <= quantum)
                    cur_T += arr[i]->left_T;
                else
                    cur_T += quantum;

                arr[i]->left_T -= quantum;

                if (arr[i]->left_T <= 0) {
                    arr[i]->Finished = true;
                    ct[i] = cur_T;
                    wt[i] = cur_T - arr[i]->arrive_T - arr[i]->burst_T;
                    tat[i] = wt[i] + arr[i]->burst_T;
                    HaveToDo --;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("#%d: AT = %d, BT = %d, CT = %d, TAT = %d, WT = %d\n", arr[i]->proc_ID, arr[i]->arrive_T, arr[i]->burst_T, ct[i], tat[i], wt[i]);

    double Trn_rnd_Avg = calc_average(tat, n);
    double delay_Avg = calc_average(wt, n);

    printf("The average turnaround time is: %.3lf\n", Trn_rnd_Avg);
    printf("The average waiting time is: %.3lf\n", delay_Avg);

}




