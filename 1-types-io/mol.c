//
// Created by hfwei on 2023/9/21.
//

#include <stdio.h>
int main(void) {
  const double MOL = 6.02E23;
  const int MOL_PER_GRAM = 32;

  int mass = 6;

  double quantity = mass * 1.0 / MOL_PER_GRAM * MOL;

  printf("quantity = %.3e\nquantity = %.5g\n",
         quantity, quantity);

  return 0;
}