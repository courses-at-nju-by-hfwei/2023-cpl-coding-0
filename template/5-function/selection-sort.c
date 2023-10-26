//
// Created by hfwei on 2023/10/12.
//

#include <stdio.h>

#define LEN 20
int numbers[LEN] = { 0 };

void Print(const int arr[], int len);

int main(void) {
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);

  Print(numbers, len);

  for (int i = 0; i < len; i++) {
    // find the minimum value of numbers[i .. n-1]
    int min = numbers[i];
    int min_index = i;

    for (int j = i + 1; j <= len - 1; ++j) {
      if (numbers[j] < min) {
        min = numbers[j];
        min_index = j;
      }
    }

    // swap numbers[i] and numbers[min_index]
    int temp = numbers[i];
    numbers[i] = numbers[min_index];
    numbers[min_index] = temp;
  }

  Print(numbers, len);

  return 0;
}

void Print(const int arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}