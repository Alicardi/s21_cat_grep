#ifndef S21_CAT_H_
#define S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

int arguments(int argc, char *argv[]);
void analiz_fun(int argc, char *argv[]);
void work_v(int *now_line);
void work_t(int *now_line);
void work_e(int *now_line);

int bflag = 0;
int eflag = 0;
int nflag = 0;
int sflag = 0;
int tflag = 0;
int vflag = 0;

static struct option long_options[] = {{"number-nonblank", 0, NULL, 'b'},
                                       {"number", 0, NULL, 'n'},
                                       {"squeeze-blank", 0, NULL, 's'},
                                       {NULL, 0, NULL, 0}};

#endif