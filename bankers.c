#include <stdio.h>
int main() {
int n, m;

printf("Enter number of processes: ");
scanf("%d", &n);

printf("Enter number of resources: ");
scanf("%d", &m);

int alloc[n][m], max[n][m], need[n][m];
int avail[m];

printf("Enter Allocation Matrix:\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
scanf("%d", &alloc[i][j]);

printf("Enter Maximum Matrix:\n");
for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
scanf("%d", &max[i][j]);

printf("Enter Available Resources:\n");
for (int i = 0; i < m; i++)
scanf("%d", &avail[i]);

// Calculate Need matrix
for (int i = 0; i < n; i++)
for (int j = 0; j < m; j++)
need[i][j] = max[i][j] - alloc[i][j];

int finish[n], safeSeq[n];
for (int i = 0; i < n; i++)
finish[i] = 0;

int work[m];
for (int i = 0; i < m; i++)
work[i] = avail[i];

int count = 0;

while (count < n) {
int found = 0;

for (int i = 0; i < n; i++) {
if (finish[i] == 0) {
int j;
for (j = 0; j < m; j++) {
if (need[i][j] > work[j])
break;
}

if (j == m) {
for (int k = 0; k < m; k++)
work[k] += alloc[i][k];

safeSeq[count++] = i;
finish[i] = 1;
found = 1;
}
}
}

if (found == 0) {
printf("\nSystem is NOT in safe state\n");
return 0;
}
}

printf("\nSystem is in SAFE state\nSafe sequence: ");
for (int i = 0; i < n; i++)
printf("P%d ", safeSeq[i]);

printf("\n");
return 0;
}
