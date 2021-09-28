#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Task {
    int arrive_T;
    int burst_T;
    int proc_ID;
    bool Finished;
}Task;

Task* new_task(int arrive_T, int burst_T, int id) {
    Task* task = malloc(sizeof (Task*));
    task->arrive_T = arrive_T;
    task->burst_T = burst_T;
    task->proc_ID = id;
    task->Finished = false;
    return task;
}

double average(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total / (n * 1.0);
}

int main() {
    int n, cur_T = 0;
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

    int complete_numb = 0;
    while (complete_numb < n) {
        Task* minTask = NULL;
        for (int i = 0; i < n; i++) {
            if (arr[i]->arrive_T <= cur_T && !arr[i]->Finished) {
                if (minTask == NULL)
                    minTask = arr[i];
                else {
                    if (minTask->burst_T > arr[i]->burst_T)
                        minTask = arr[i];
                }
            }
        }
        if (minTask == NULL)
            cur_T++;
        else {
            int taskId = minTask->proc_ID - 1;

            wt[taskId] = cur_T - minTask->arrive_T;

            cur_T += minTask->burst_T;

            ct[taskId] = cur_T;

            tat[taskId] = wt[taskId] + minTask->burst_T;

            minTask->Finished = true;

            complete_numb++;
        }
    }

    for (int i = 0; i < n; i++)
        printf("#%d: AT = %d, BT = %d, CT = %d, TAT = %d, WT = %d\n", arr[i]->proc_ID, arr[i]->arrive_T, arr[i]->burst_T, ct[i], tat[i], wt[i]);

    double avg_trn_rnd = average(tat, n);
    double delay_avg = average(wt, n);

    printf("The average turnaround time is: %.3lf\n", avg_trn_rnd);
    printf("The average waiting time is: %.3lf\n", delay_avg);
}
