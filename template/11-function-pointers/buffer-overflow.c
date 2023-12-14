//
// Created by hfwei on 2023/12/13.
// Visualization: https://pythontutor.com/render.html#code=%23include%20%3Cstdio.h%3E%0A%0Avoid%20Hi%28void%29%3B%0Avoid%20func%28void%29%3B%0A%0Aint%20main%28void%29%20%7B%0A%20%20func%28%29%3B%0A%0A%20%20return%200%3B%0A%7D%0A%0Avoid%20Hi%28void%29%20%7B%0A%20%20printf%28%22Hi%5Cn%22%29%3B%0A%7D%0A%0Avoid%20func%28void%29%20%7B%0A%20%20void%20*buf%5B2%5D%3B%0A%20%20static%20int%20i%3B%0A%0A%20%20for%20%28i%20%3D%200%3B%20i%20%3C%2010%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20buf%5Bi%5D%20%3D%20Hi%3B%0A%20%20%7D%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=15&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
// Sorry, I do not fully understand this code.
//

#include <stdio.h>

void Hi(void);
void func(void);

int main(void) {
  // int buf[100];
  func();

  return 0;
}

void Hi(void) {
  printf("Hi\n");
}

void func(void) {
  void *buf[2];
  static int i;

  for (i = 0; i < 10; i++) {
    buf[i] = Hi;
  }
}