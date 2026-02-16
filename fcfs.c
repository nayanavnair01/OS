#include <stdio.h>
int main() {
int n, i, j;
int pid[10], at[10], bt[10], wt[10], ct[10], tat[10];
int time = 0, total_wt = 0, total_tat = 0;

printf("Enter number of processes: ");
scanf("%d", &n);

for (i = 0; i < n; i++) {
pid[i] = i + 1;
printf("Arrival time of P%d: ", pid[i]);
scanf("%d", &at[i]);
printf("Burst time of P%d: ", pid[i]);
scanf("%d", &bt[i]);
}


for (i = 0; i < n - 1; i++) {
for (j = i + 1; j < n; j++) {
if (at[i] > at[j]) {
int temp;
temp = at[i]; at[i] = at[j]; at[j] = temp;
temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
}
}
}


printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
for (i = 0; i < n; i++) {
if (time < at[i])
time = at[i];
time += bt[i];
ct[i] = time;
tat[i] = ct[i] - at[i];
wt[i] = tat[i] - bt[i];
total_wt += wt[i];
total_tat += tat[i];

printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
}

printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);

return 0;
}
