//
// Created by hfwei on 2023/12/13.
//

#include <stdio.h>
#include <string.h>

// See https://codebrowser.dev/glibc/glibc/stdlib/stdlib.h.html#__compar_fn_t
typedef int (*__compar_fn_t)(const void *, const void *);

// See https://codebrowser.dev/glibc/glibc/bits/stdlib-bsearch.h.html#19
void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size,
              __compar_fn_t __compar);

int CompareStrs(const void *left, const void *right);

int main(void) {
  const char *names[] = {
      "Cui Jian",
      "Dou Wei",
      "He Yong",
      "Hu Mage",
      "Li Zhi",
      "Luo Dayou",
      "Wan Qing",
      "WuTiaoRen",
      "Zhang Chu",
      "ZuoXiao",
  };

  char *key_name = "Zhang Chu";

  char **name_ptr = bsearch(&key_name, names,
                            sizeof names / sizeof *names,
                            sizeof *names,
                            (__compar_fn_t) strcmp);

  // char **name_ptr = bsearch("Zhang Chu", names,
  //                           sizeof names / sizeof *names,
  //                           sizeof *names,
  //                           CompareStrs);

  printf("name: %s\n", *name_ptr);  // name: Zhang Chu

  return 0;
}

void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size,
              __compar_fn_t __compar) {
  size_t __l, __u, __idx;
  const void *__p;
  int __comparison;
  __l = 0;
  __u = __nmemb;
  while (__l < __u) {
    __idx = (__l + __u) / 2;
    __p = (const void *) (((const char *) __base) + (__idx * __size));
    __comparison = (*__compar)(__key, __p);
    if (__comparison < 0) {
      __u = __idx;
    } else if (__comparison > 0) {
      __l = __idx + 1;
    } else {
      return (void *) __p;
    }
  }
  return NULL;
}

int CompareStrs(const void *left, const void *right) {
  const char *pp1 = left;
  char *const *pp2 = right;
  return strcmp(pp1, *pp2);
}