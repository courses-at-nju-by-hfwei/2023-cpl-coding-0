//
// Created by hfwei on 2023/10/12.
//

#include <stdio.h>

#define LEN 20
int numbers[LEN] = {0};

void SelectionSort(int arr[], int len);
void WrongSwap(int left, int right);
int GetMinIndex(const int arr[], int begin, int end);
void Print(const int arr[], int len);

int main(void) {
  int len = -1;
  while (scanf("%d", &numbers[++len]) != EOF);

  // sizeof numbers / sizeof(numbers[0])
  Print(numbers, len);
  SelectionSort(numbers, len);
  Print(numbers, len);

  return 0;
}

// arr: the (copy of the) address of the first element of the `numbers` array
void SelectionSort(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    int min_index = GetMinIndex(arr, i, len);

    // ERROR: WrongSwap(arr[i], arr[min_index]);
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

int GetMinIndex(const int arr[], int begin, int end) {
  int min = arr[begin];
  int min_index = begin;

  for (int i = begin + 1; i < end; ++i) {
    if (arr[i] < min) {
      min = arr[i];
      min_index = i;
    }
  }

  return min_index;
}

void WrongSwap(int left, int right) {
  int temp = left;
  left = right;
  right = temp;
}

void Print(const int arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}