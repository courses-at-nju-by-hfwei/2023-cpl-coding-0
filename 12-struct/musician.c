//
// Created by hfwei on 2022/12/8.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum gender {
  MALE,
  FEMALE,
} Gender;

typedef struct score {
  int c_score;
  int java_score;
  int python_score;
} Score;

typedef struct musician {
  char *name;
  // char gender;
  Gender gender;
  char *album;

  Score score;
} Musician;

// void PrintMusician(const Musician m);
void PrintMusician(const Musician *m);
int CompareMusician(const void *m1, const void *m2);

int main() {
  printf("sizeof(Score) = %zu\n", sizeof(Score));
  printf("sizeof(Musician) = %zu\n", sizeof(Musician));
  printf("offsetof(Musician, name) = %zu\n", offsetof(Musician, name));
  printf("offsetof(Musician, gender) = %zu\n", offsetof(Musician, gender));
  printf("offsetof(Musician, album) = %zu\n", offsetof(Musician, album));
  printf("offsetof(Musician, score) = %zu\n", offsetof(Musician, score));

  Musician luo = {
      .name = "Luo Dayou",
      .gender = MALE,
      .album = "ZhiHuZheYe",
      .score = {
          .c_score = 0,
          .java_score = 10,
          .python_score = 20,
      },
  };

  Musician cui = {
      .name = "Cui Jian",
      .gender = MALE,
      .album = "XinChangZhengLuShangDeYaoGun",
      .score = {
          .c_score = 10,
          .java_score = 20,
          .python_score = 30,
      },
  };

  char album[] = "YiKeBuKenMeiSuDeXin";
  Musician zhang = {
      .name = "Zhang Chu",
      .gender = MALE,
      // .album = "YiKeBuKenMeiSuDeXin",
      .album = album,
      .score = {
          .c_score = 20,
          .java_score = 30,
          .python_score = 40,
      },
  };

  Musician guo = zhang;
  guo.name = "Guo Fucheng";
  strcpy(guo.album, "YiKeJiuMeiSuDeXin");
  // PrintMusician(guo);
  // PrintMusician(zhang);
  PrintMusician(&guo);
  PrintMusician(&zhang);

  Musician musicians[] = { luo, cui, zhang, };
  int len = sizeof musicians / sizeof *musicians;
  for (int i = 0; i < len; ++i) {
    // PrintMusician(musicians[i]);
    PrintMusician(&musicians[i]);
  }

  qsort(musicians, len,
        sizeof *musicians,
        CompareMusician);

  for (int i = 0; i < len; ++i) {
    // PrintMusician(musicians[i]);
    PrintMusician(&musicians[i]);
  }

  return 0;
}

// void PrintMusician(const Musician m) {
//   printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
//          m.name,
//          m.gender,
//          m.album,
//          m.score.c_score,
//          m.score.java_score,
//          m.score.python_score);
// }

void PrintMusician(const Musician *m) {
  printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
         m->name,
         m->gender,
         m->album,
         m->score.c_score,
         m->score.java_score,
         m->score.python_score);
}

int CompareMusician(const void *m1, const void *m2) {
  const Musician *m_left = m1;
  const Musician *m_right = m2;

  return strcmp(m_left->album, m_right->album);
}