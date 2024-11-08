#include<stdio.h>

int main() {
    int n, i, j;
    float total_wait = 0, total_turnaround = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], arrival_time[n], wait_time[n], turnaround_time[n], completion_time[n];

    // Input arrival time and burst time for each process
    for(i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
    }
        for(i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sort processes by arrival time using a simple bubble sort
//    for(i = 0; i < n-1; i++) {
//        for(j = 0; j < n-i-1; j++) {
//            if(arrival_time[j] > arrival_time[j+1]) {
//                // Swap arrival time
//                int temp = arrival_time[j];
//                arrival_time[j] = arrival_time[j+1];
//                arrival_time[j+1] = temp;
//
//                // Swap burst time accordingly
//                temp = burst_time[j];
//                burst_time[j] = burst_time[j+1];
//                burst_time[j+1] = temp;
//            }
//        }
//    }

    // Calculating completion time, waiting time and turnaround time
    completion_time[0] = arrival_time[0] + burst_time[0];
    turnaround_time[0] = completion_time[0] - arrival_time[0];
    wait_time[0] = turnaround_time[0] - burst_time[0];

    for(i = 1; i < n; i++) {
        if(completion_time[i-1] < arrival_time[i]) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = completion_time[i-1] + burst_time[i];
        }
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        wait_time[i] = turnaround_time[i] - burst_time[i];
    }

    // Outputting results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], wait_time[i], turnaround_time[i], completion_time[i]);
        total_wait += wait_time[i];
        total_turnaround += turnaround_time[i];
    }

    // Printing average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", total_wait / n);
    printf("\nAverage Turnaround Time: %.2f", total_turnaround / n);

    return 0;
}

