//
// file: strlen.c
// Created by hfwei on 2023/11/29.
//

#include <stdio.h>

int StrLen(const char *s);
size_t StrLenStd(const char *s);

int main() {
  char msg[] = "Hello World!";

  printf("StrLen(%s) = %d\n", msg, StrLen(msg));
  printf("StrLenStd(%s) = %zu\n", msg, StrLenStd(msg));

  return 0;
}

// int StrLen(const char *s) {
//   int len = 0;
//   while (s[len] != '\0') {
//     len++;
//   }
//
//   return len;
// }

// int StrLen(const char *s) {
//   int len = 0;
//   while (s[len++] != '\0');
//
//   return len - 1;
// }

// Correct but ugly version
// int StrLen(const char *s) {
//   int len = -1;
//   while (s[++len] != '\0');
//
//   return len;
// }

size_t StrLenStd(const char *s) {
  const char *sc;
  for (sc = s; *sc != '\0'; sc++);

  return sc - s;
}