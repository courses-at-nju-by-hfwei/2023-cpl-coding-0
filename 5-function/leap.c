//
// Created by hfwei on 2023/10/6.
//

#include <stdio.h>
#include <stdbool.h>

bool IsLeapYear(int year);

int main(void) {
  // year: in the main function: local variable
  // life time:
  // scope: from this point on until the main function exits
  int year = 0;
  scanf("%d", &year);

  if (IsLeapYear(year)) {
    printf("%d is a leap year\n", year);
  } else {
    printf("%d is a common year\n", year);
  }

  return 0;
}

// year: parameter
// life time
// scope as a local variable
bool IsLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}