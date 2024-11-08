#include <stdio.h>

void priorityScheduling(int n, int processes[], int burstTime[], int priority[]) {
    int waitTime[n], turnAroundTime[n], totalWaitTime = 0, totalTurnaroundTime = 0;

  
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] < priority[j]) {
    
                int temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

  
    waitTime[0] = 0;

  
    for (int i = 1; i < n; i++) {
        waitTime[i] = burstTime[i - 1] + waitTime[i - 1];
    }

 
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitTime[i];
    }

  
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitTime += waitTime[i];
        totalTurnaroundTime += turnAroundTime[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], priority[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)totalWaitTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], priority[n];
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }

  
    priorityScheduling(n, processes, burstTime, priority);

    return 0;
}

