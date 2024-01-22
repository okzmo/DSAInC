#include <stdio.h>

int partition(int numbers[], int lo, int hi) {
  int pivot = numbers[hi];
  int idx = lo - 1;

  for (int i = lo; i < hi; i++) {
    if (numbers[i] <= pivot) {
      idx++;
      int tmp = numbers[i];
      numbers[i] = numbers[idx];
      numbers[idx] = tmp;
    }
  }

  idx++;
  numbers[hi] = numbers[idx];
  numbers[idx] = pivot;

  return idx;
}

void qs(int numbers[], int lo, int hi) {
  if (lo >= hi) {
    return;
  }

  int pivotIdx = partition(numbers, lo, hi);

  qs(numbers, lo, pivotIdx - 1);
  qs(numbers, pivotIdx + 1, hi);
}

int main() {
  int numbers[] = {2, 8, 5, 9, 2, 10, 82, 0, 823};
  int length = sizeof(numbers) / sizeof(numbers[0]);

  qs(numbers, 0, length - 1);
  for (int i = 0; i < length; i++) {
    printf("%d,", numbers[i]);
  }
}
