//
// Created by hfwei on 2022/11/10.
//

#include <limits.h>
#include <stdio.h>

int SquareInt(int num);
double SquareDouble(double num);

int main() {
  // narrowing conversion (still in the range)
  int i = 3.14159;

  // out of the range: undefined behavior!!!
  int j = UINT_MAX;

  // arguments; narrowing conversion
  double k = 3.14159;
  SquareInt(k);

  // return value; narrowing conversion
  int m = SquareDouble(k);

  int big = 1234567890;
  float approx = big;
  int approx_big = (int) approx;
  printf("big = %d\t approx = %f\t approx_big = %d\t diff = %d\n",
         big, approx, approx_big, big - (int) approx);

  return 0;
}

int SquareInt(int num) {
  return num * num;
}

double SquareDouble(double num) {
  return num * num;
}