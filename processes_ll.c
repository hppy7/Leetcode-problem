#include <stdio.h>
#include <stdlib.h>

// Define the structure for each process in the circular linked list
typedef struct process {
    int id;                  // Process ID
    int burst_time;          // Burst time needed for process
    struct process* next;    // Pointer to the next process in the list
} process;

// Function to create a new process node
process* createProcess(int id, int burst_time) {
    process* newProcess = (process*)malloc(sizeof(process));
    newProcess->id = id;
    newProcess->burst_time = burst_time;
    newProcess->next = NULL;
    return newProcess;
}

// Function to append a process to the circular linked list
void appendProcess(process** head, int id, int burst_time) {
    process* newProcess = createProcess(id, burst_time);
    if (*head == NULL) {
        *head = newProcess;
        newProcess->next = *head; // Circular link
    } else {
        process* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newProcess;
        newProcess->next = *head; // Circular link
    }
}

// Function to simulate the time-sharing environment
void timeSharing(process* head, int time_slot, int total_processes) {
    process* current = head;
    int completedProcesses = 0; // Track completed processes
    int total_time = 0;         // Track total time elapsed
    
    while (completedProcesses < total_processes) { // Repeat until all processes are completed
        if (current->burst_time > 0) {
            if (current->burst_time <= time_slot) { // Process can be completed in this time slot
                total_time += current->burst_time;
                printf("Process %d completed in %d ns\n", current->id, total_time);
                current->burst_time = 0;
                completedProcesses++;
            } else { // Process needs more time slots
                current->burst_time -= time_slot;
                total_time += time_slot;
            }
        }
        current = current->next; // Move to the next process
    }
}

int main() {
    process* head = NULL; // Initialize head of the circular linked list
    int N, i, burst_time;
    
    printf("Enter the number of processes: ");
    scanf("%d", &N);
    
    for (i = 1; i <= N; i++) {
        printf("Enter burst time for Process %d: ", i);
        scanf("%d", &burst_time);
        appendProcess(&head, i, burst_time);
    }
    
    int time_slot;
    printf("Enter the time slot for each process (in ns): ");
    scanf("%d", &time_slot);

    printf("\nTime-sharing simulation:\n");
    timeSharing(head, time_slot, N);
    
    return 0;
}
