/**
 * @author hfwei
 * @date 2023-09-16
 */
// preprocessor directives
// stdio: standard input output
// .h: header file
// gcc -E hello.c
#include <stdio.h>

/*
 * This is the main function.
 * Any executable C program must contain one and only one main funciton.
 * function: y <- f(x)
 * main: int <- f()
 *   does not accept arguments
 *   returns an integer (to OS)
 * about int
 * about void
 */
int main() {
  /*
   * printf: print + f: format
   */
  printf("Hello, World!\n"); /* return an integer */

  // return with exit code 0
  return 0;
}