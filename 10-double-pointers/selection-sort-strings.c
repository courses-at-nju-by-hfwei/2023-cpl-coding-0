// file: selection-sort-strings.c
// Created by hfwei on 2023/12/07.

#include <stdio.h>
#include <string.h>

// (8) char *arr[]
void SelectionSort(const char *arr[], int len);
// (9)
int GetMinIndex(const char *arr[], int begin, int end);
// (11)
void Swap(const char **left, const char **right);
// (4) char *arr[]
void Print(const char *arr[], int len);

// (0): delete all "const" first
// (final): add "const" back
int main() {
  // (1) type
  // (2) visualization: https://pythontutor.com/render.html#code=int%20main%28void%29%20%7B%0A%20%20const%20char%20*musicians%5B%5D%20%3D%20%7B%0A%20%20%20%20%20%20%22Luo%20Dayou%22,%0A%20%20%20%20%20%20%22Cui%20Jian%22,%0A%20%20%20%20%20%20%22Dou%20Wei%22,%0A%20%20%20%20%20%20%22Zhang%20Chu%22,%0A%20%20%20%20%20%20%22Wan%20Qing%22,%0A%20%20%20%20%20%20%22Li%20Zhi%22,%0A%20%20%20%20%20%20%22Yao%22,%0A%20%20%20%20%20%20%22ZuoXiao%22,%0A%20%20%20%20%20%20%22ErShou%20Rose%22,%0A%20%20%20%20%20%20%22Hu%20Mage%22,%0A%20%20%7D%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&cppShowMemAddrs=true&cumulative=true&curInstr=1&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
  const char *musicians[] = {
      "Luo Dayou",
      "Cui Jian",
      "Dou Wei",
      "Zhang Chu",
      "Wan Qing",
      "Li Zhi",
      "Yao",
      "ZuoXiao",
      "ErShou Rose",
      "Hu Mage",
  };

  // (3) sizeof
  // (3) sizeof(*musicians)
  int len = sizeof(musicians) / sizeof(musicians[0]);
  Print(musicians, len);
  SelectionSort(musicians, len);
  Print(musicians, len);

  return 0;
}

// (8) char *arr[]
void SelectionSort(const char *arr[], int len) {
  for (int i = 0; i < len; i++) {
    // (9)
    int min_index = GetMinIndex(arr, i, len);

    // (11)
    // (13): consider the WRONG version also
    Swap(arr + i, arr + min_index);
  }
}

// (9) const char *arr[]
int GetMinIndex(const char *arr[], int begin, int end) {
  const char *min = arr[begin];
  int min_index = begin;

  for (int i = begin + 1; i < end; ++i) {
    // (10) strcmp [-1]
    if (strcmp(arr[i], min) < 0) {
      min = arr[i];
      min_index = i;
    }
  }

  return min_index;
}

// (12)
// visualization: https://pythontutor.com/render.html#code=//%20file%3A%20selection-sort-strings.c%0A//%20Created%20by%20hfwei%20on%202023/12/07.%0A%0A%23include%20%3Cstdio.h%3E%0A%23include%20%3Cstring.h%3E%0A%23include%20%3Cstdlib.h%3E%0A%0Avoid%20SelectionSort%28const%20char%20*arr%5B%5D,%20int%20len%29%3B%0Aint%20GetMinIndex%28const%20char%20*arr%5B%5D,%20int%20begin,%20int%20end%29%3B%0Avoid%20Swap%28const%20char%20**left,%20const%20char%20**right%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20const%20char%20*musicians%5B%5D%20%3D%20%7B%0A%20%20%20%20%20%20%22Luo%20Dayou%22,%0A%20%20%20%20%20%20%22Cui%20Jian%22,%0A%20%20%20%20%20%20%22Dou%20Wei%22,%0A%20%20%7D%3B%0A%0A%20%20int%20len%20%3D%20sizeof%28musicians%29%20/%20sizeof%28musicians%5B0%5D%29%3B%0A%20%20SelectionSort%28musicians,%20len%29%3B%0A%0A%20%20return%200%3B%0A%7D%0A%0Avoid%20SelectionSort%28const%20char%20*arr%5B%5D,%20int%20len%29%20%7B%0A%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20len%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20//%20%289%29%0A%20%20%20%20int%20min_index%20%3D%20GetMinIndex%28arr,%20i,%20len%29%3B%0A%0A%20%20%20%20Swap%28arr%20%2B%20i,%20arr%20%2B%20min_index%29%3B%0A%20%20%7D%0A%7D%0A%0Aint%20GetMinIndex%28const%20char%20*arr%5B%5D,%20int%20begin,%20int%20end%29%20%7B%0A%20%20const%20char%20*min%20%3D%20arr%5Bbegin%5D%3B%0A%20%20int%20min_index%20%3D%20begin%3B%0A%0A%20%20for%20%28int%20i%20%3D%20begin%20%2B%201%3B%20i%20%3C%20end%3B%20%2B%2Bi%29%20%7B%0A%20%20%20%20if%20%28strcmp%28arr%5Bi%5D,%20min%29%20%3C%200%29%20%7B%0A%20%20%20%20%20%20min%20%3D%20arr%5Bi%5D%3B%0A%20%20%20%20%20%20min_index%20%3D%20i%3B%0A%20%20%20%20%7D%0A%20%20%7D%0A%0A%20%20return%20min_index%3B%0A%7D%0A%0Avoid%20Swap%28const%20char%20**left,%20const%20char%20**right%29%20%7B%0A%20%20const%20char%20*temp%20%3D%20*left%3B%0A%20%20*left%20%3D%20*right%3B%0A%20%20*right%20%3D%20temp%3B%0A%7D&cumulative=true&curInstr=0&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
void Swap(const char **left, const char **right) {
  const char *temp = *left;
  *left = *right;
  *right = temp;
}

// (6) char *arr[]: char **arr
// (7) char *arr[] vs. char *arr[]
void Print(const char *arr[], int len) {
  printf("\n");
  for (int i = 0; i < len; i++) {
    // (5) arr[i]: *(arr + i)
    printf("%s\n", arr[i]);
  }
  printf("\n");
}

// "Luo Dayou",
// "Cui Jian",
// "Dou Wei",
// "Zhang Chu",
// "Wan Qing",
// "Li Zhi",
// "Yao",
// "ZuoXiao",
// "ErShou Rose",
// "Hu Mage",