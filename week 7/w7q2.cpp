#include <stdio.h>

void roundRobin(int processes[], int n, int burstTime[], int quantum) {
    int remainingTime[n];
    int waitTime[n], turnaroundTime[n];
    int totalWaitTime = 0, totalTurnaroundTime = 0;
    int time = 0; 

    
    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
        waitTime[i] = 0;  
    }

   
    while (1) {
        int done = 1; 

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = 0; 

                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    waitTime[i] = time - burstTime[i];  
                    remainingTime[i] = 0;             
                }
            }
        }

        if (done == 1)
            break;  
    }

 
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitTime[i];
        totalWaitTime += waitTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

   
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burstTime[i], waitTime[i], turnaroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n, quantum;


    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n];


    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }


    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

   
    roundRobin(processes, n, burstTime, quantum);

    return 0;
}

