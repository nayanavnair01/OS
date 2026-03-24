#include <stdio.h>
#include <stdlib.h>
#include<time.h> 
#define MAX 50


void generatePages(int pages[], int n) {
for(int i = 0; i < n; i++) {
pages[i] = rand() % 10; // 0–9
}
}

// FIFO Algorithm
int fifo(int pages[], int n, int frames) {
int frame[10], index = 0, faults = 0;

for(int i = 0; i < frames; i++)
frame[i] = -1;

for(int i = 0; i < n; i++) {
int found = 0;

for(int j = 0; j < frames; j++) {
if(frame[j] == pages[i]) {
found = 1;
break;
}
}

if(!found) {
frame[index] = pages[i];
index = (index + 1) % frames;
faults++;
}
}
return faults;
}

// LRU Algorithm
int lru(int pages[], int n, int frames) {
int frame[10], time[10], faults = 0, t = 0;

for(int i = 0; i < frames; i++) {
frame[i] = -1;
time[i] = 0;
}

for(int i = 0; i < n; i++) {
int found = 0;

for(int j = 0; j < frames; j++) {
if(frame[j] == pages[i]) {
found = 1;
time[j] = ++t;
break;
}
}

if(!found) {
int lru_index = 0;

for(int j = 1; j < frames; j++) {
if(time[j] < time[lru_index])
lru_index = j;
}

frame[lru_index] = pages[i];
time[lru_index] = ++t;
faults++;
}
}
return faults;
}

// Optimal Algorithm
int optimal(int pages[], int n, int frames) {
int frame[10], faults = 0;

for(int i = 0; i < frames; i++)
frame[i] = -1;

for(int i = 0; i < n; i++) {
int found = 0;

for(int j = 0; j < frames; j++) {
if(frame[j] == pages[i]) {
found = 1;
break;
}
}

if(!found) {
int pos = -1, farthest = i;

for(int j = 0; j < frames; j++) {
int k;
for(k = i + 1; k < n; k++) {
if(frame[j] == pages[k])
break;
}

if(k == n) {
pos = j;
break;
}

if(k > farthest) {
farthest = k;
pos = j;
}
}

if(pos == -1)
pos = 0;

frame[pos] = pages[i];
faults++;
}
}
return faults;
}

int main() {
int pages[MAX], n = 20, frames = 3;

srand(time(0));

generatePages(pages, n);

printf("Page Reference String:\n");
for(int i = 0; i < n; i++)
printf("%d ", pages[i]);

printf("\n\nFrames: %d\n", frames);

printf("\nFIFO Page Faults = %d", fifo(pages, n, frames));
printf("\nLRU Page Faults = %d", lru(pages, n, frames));
printf("\nOptimal Page Faults = %d\n", optimal(pages, n, frames));

return 0;
}
