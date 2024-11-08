#include<stdio.h>

int main() {
    int n, i, j, pos, temp;
    float total_wait = 0, total_turnaround = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst_time[n], arrival_time[n], wait_time[n], turnaround_time[n], completion_time[n], process[n];

    // Input burst time and arrival time for each process
    for(i = 0; i < n; i++) {
        process[i] = i + 1; // Storing process numbers
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrival_time[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Sort processes based on burst time using selection sort (non-preemptive SJF)
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(burst_time[j] < burst_time[pos]) {
                pos = j;
            }
        }

        // Swap burst time
        temp = burst_time[i];
        burst_time[i] = burst_time[pos];
        burst_time[pos] = temp;

        // Swap process numbers
        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;

        // Swap arrival times
        temp = arrival_time[i];
        arrival_time[i] = arrival_time[pos];
        arrival_time[pos] = temp;
    }

    // First process to execute
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

    // Output the results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival_time[i], burst_time[i], wait_time[i], turnaround_time[i]);
        total_wait += wait_time[i];
        total_turnaround += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wait / n);
    printf("\nAverage Turnaround Time: %.2f", total_turnaround / n);

    return 0;
}

